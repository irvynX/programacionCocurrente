import cv2
import numpy as np
import os

def resize_image(image, width, height):
    # Obtener las dimensiones originales de la imagen
    original_height, original_width = image.shape[:2]

    # Calcular el factor de escala para redimensionar la imagen
    scale_factor = min(width / original_width, height / original_height)

    # Calcular las nuevas dimensiones
    new_width = int(original_width * scale_factor)
    new_height = int(original_height * scale_factor)

    # Redimensionar la imagen utilizando la interpolación bilineal
    resized_image = cv2.resize(image, (new_width, new_height), interpolation=cv2.INTER_LINEAR)

    return resized_image

def segment_image(image_path):
    # Cargar la imagen
    image = cv2.imread(image_path)

    # Redimensionar la imagen a un tamaño específico
    resized_image = resize_image(image, 800, 600)

    # Convertir la imagen redimensionada a escala de grises
    gray = cv2.cvtColor(resized_image, cv2.COLOR_BGR2GRAY)

    # Aplicar un umbral para obtener una imagen binaria
    _, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

    # Detección de color para segmentar células infectadas
    hsv = cv2.cvtColor(resized_image, cv2.COLOR_BGR2HSV)
    lower_color = np.array([140, 50, 50])  # Rango inferior de color morado
    upper_color = np.array([170, 255, 255])  # Rango superior de color morado
    mask = cv2.inRange(hsv, lower_color, upper_color)
    result = cv2.bitwise_and(thresh, thresh, mask=mask)

    # Encontrar los contornos de las regiones de interés
    contours, _ = cv2.findContours(result, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Crear una lista para almacenar los rois
    rois = []

    # Valores de ajuste del recorte de los ROIs
    offset = 10
    expansion = 20
    # Iterar sobre los contornos y obtener los rois
    for contour in contours:
        # Obtener el rectángulo del contorno con un pequeño desplazamiento
        x, y, w, h = cv2.boundingRect(contour)
        x -= 2
        y -= 2
        w += 5
        h += 5

        # Asegurarse de que los valores no sean negativos o excedan las dimensiones de la imagen
        x = max(0, x)
        y = max(0, y)
        w = min(w, resized_image.shape[1] - x)
        h = min(h, resized_image.shape[0] - y)

        # Añadir el roi a la lista
        roi = resized_image[y:y + h, x:x + w]
        rois.append(roi)

        # Dibujar un rectángulo alrededor del roi en la imagen original
        #cv2.rectangle(resized_image, (x, y), (x + w, y + h), (0, 255, 0), 2)

        # Guardar el roi como una imagen individual
        cv2.imwrite(f'roi_{len(rois)}.jpg', roi)

    # Mostrar la imagen redimensionada con los rois y esperar la tecla 'q' para cerrarla
    cv2.imshow('Resized Image with ROIs', resized_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

    return rois

# Carpeta que contiene las imágenes
folder_path = 'img/'

# Obtener la lista de imágenes en la carpeta
image_files = os.listdir(folder_path)

# Segmentar cada imagen en la carpeta
for image_file in image_files:
    # Ruta completa de la imagen
    image_path = os.path.join(folder_path, image_file)

    # Segmentar la imagen y obtener los rois
    rois = segment_image(image_path)
