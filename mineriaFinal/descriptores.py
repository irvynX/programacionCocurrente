# pip install mahotas
import os
import csv
import cv2
import mahotas.features.texture as mht
from skimage.measure import moments
import numpy as np

def obtener_descriptores(imagen):
    # Descriptores de textura (GLCM)
    imagen_gris = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)
    glcm = mht.haralick(imagen_gris)
    contraste = np.expand_dims(glcm.mean(axis=0)[2], axis=0)
    energia = np.expand_dims(glcm.mean(axis=0)[4], axis=0)
    homogeneidad = np.expand_dims(glcm.mean(axis=0)[8], axis=0)

    # Descriptores de forma (momentos de Hu)
    imagen_binaria = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)
    _, imagen_binaria = cv2.threshold(imagen_binaria, 127, 255, cv2.THRESH_BINARY)
    momentos_hu = cv2.HuMoments(cv2.moments(imagen_binaria)).flatten()

    # Descriptores de color (media y desviación estándar en cada canal)
    media_color = np.mean(imagen, axis=(0, 1))
    desviacion_estandar_color = np.std(imagen, axis=(0, 1))

    return np.concatenate((contraste, energia, homogeneidad, momentos_hu, media_color, desviacion_estandar_color))

# Ruta de la carpeta con las imágenes
carpeta_imagenes = 'imgROI/'

# Lista para almacenar los descriptores de todas las imágenes
descriptores_total = []

# Recorrer todas las imágenes en la carpeta
for nombre_archivo in os.listdir(carpeta_imagenes):
    ruta_imagen = os.path.join(carpeta_imagenes, nombre_archivo)

    # Leer la imagen
    imagen = cv2.imread(ruta_imagen)

    # Obtener los descriptores de la imagen
    descriptores = obtener_descriptores(imagen)

    # Agregar los descriptores a la lista total
    descriptores_total.append(descriptores)

# Encabezados de las columnasimport os
import csv
import cv2
import mahotas.features.texture as mht
from skimage.measure import moments
import numpy as np

def obtener_descriptores(imagen):
    # Descriptores de textura (GLCM)
    imagen_gris = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)
    glcm = mht.haralick(imagen_gris)
    contraste = np.expand_dims(glcm.mean(axis=0)[2], axis=0)
    energia = np.expand_dims(glcm.mean(axis=0)[4], axis=0)
    homogeneidad = np.expand_dims(glcm.mean(axis=0)[8], axis=0)

    # Descriptores de forma (momentos de Hu)
    imagen_binaria = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)
    _, imagen_binaria = cv2.threshold(imagen_binaria, 127, 255, cv2.THRESH_BINARY)
    momentos_hu = cv2.HuMoments(cv2.moments(imagen_binaria)).flatten()

    # Descriptores de color (media y desviación estándar en cada canal)
    media_color = np.mean(imagen, axis=(0, 1))
    desviacion_estandar_color = np.std(imagen, axis=(0, 1))

    # Descriptor de clase (valor 1)
    clase = 0 # <--------------------------------------------------------------------------------- cambiar la clase dependiendo del tipo

    return np.concatenate((contraste, energia, homogeneidad, momentos_hu, media_color, desviacion_estandar_color, [clase]))

# Ruta de la carpeta con las imágenes
carpeta_imagenes = 'imgROI/'

# Lista para almacenar los descriptores de todas las imágenes
descriptores_total = []

# Recorrer todas las imágenes en la carpeta
for nombre_archivo in os.listdir(carpeta_imagenes):
    ruta_imagen = os.path.join(carpeta_imagenes, nombre_archivo)

    # Leer la imagen
    imagen = cv2.imread(ruta_imagen)

    # Obtener los descriptores de la imagen
    descriptores = obtener_descriptores(imagen)

    # Agregar los descriptores a la lista total
    descriptores_total.append(descriptores)

# Encabezados de las columnas
encabezados = ['#Contraste', '#Energia', '#Homogeneidad', '#Momento_Hu1', '#Momento_Hu2', '#Momento_Hu3', '#Momento_Hu4', '#Momento_Hu5', '#Momento_Hu6', '#Momento_Hu7', '#Media_Color_R', '#Media_Color_G', '#Media_Color_B', '#Desv_Estandar_Color_R', '#Desv_Estandar_Color_G', '#Desv_Estandar_Color_B', '#Clase']

#Contraste: Mide la diferencia de intensidad entre un píxel y sus vecinos. 
#Energía: También conocida como el segundo momento angular, representa la suma de los valores al cuadrado en la matriz de co-ocurrencia de niveles de gris.
#Homogeneidad: Mide la proximidad de los valores en la matriz de co-ocurrencia a la diagonal principal. Un valor alto indica una mayor uniformidad.
#Hi1: mide que tan redondo es
#Hu2: simetria con el eje vertical
#Hu3: simetria con el eje horizontal
#Hu4: Es una medida de la simetría diagonal. Tiene un valor positivo para formas simétricas respecto a la diagonal principal y un valor negativo para formas asimétricas.
#Hu5: Es positivo para formas más pesadas en la parte superior y negativo para formas más pesadas en la parte inferior.
#Hu6: Es positivo para formas más pesadas en la parte izquierda y negativo para formas más pesadas en la parte derecha.
#Hu7: Su valor es mayor para formas más compactas y tiende a cero para formas más dispersas.
#media: La media de los valores de los canales Rojo (R), Verde (G) y Azul (B) en la imagen
#desviacion: La desviación estándar de los valores de los canales R, G y B en la imagen, respectivamente. Mide la variabilidad de los valores de color en la imagen.

# Guardar los descriptores en un archivo CSV
ruta_archivo_csv = 'descriptores.csv'
with open(ruta_archivo_csv, 'w', newline='') as archivo_csv:
    escritor_csv = csv.writer(archivo_csv)

    # Escribir los encabezados comentados
    escritor_csv.writerow(['#'] + encabezados)

    # Escribir los descriptores
    for descriptor in descriptores_total:
        escritor_csv.writerow([''] + list(descriptor))

print('Descriptores guardados en', ruta_archivo_csv)

