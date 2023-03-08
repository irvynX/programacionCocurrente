from PIL import Image
import statistics
import glob
import numpy as np
import os

dirO = "imgO/img"
dirM = "imgM/m"
punto = ".png"


#variables de los descriptores
variaMini = 99999999.0
contrMini = 99999999.0
colorMini = 99999999.0
energMini = 99999999.0
variaMax = 0.0
contrMax = 0.0
colorMax = 0.0
energMax = 0.0
clasificador = ""
for posOrig in range(1, 3):
    # Abre la imagen original y recupera sus mascaras
    imgO = Image.open(dirO + str(posOrig) + punto).convert("RGB")
    #recupera las mascaras
    direcM = glob.glob(dirM + str(posOrig) + '/*')
    numMascaras = len(direcM)
    #print(numMascaras)
    for i in range(numMascaras):
        #abrimos la mascar
        print(direcM[i])
        imgM = Image.open(direcM[i]).convert("RGB")
        #obtenemos el clasificador
        if os.path.basename(direcM[i]) == 'f.png':
            clasificador = 'fuego'
        elif os.path.basename(direcM[i]) == 'h.png':
            clasificador = 'humo'
        else:
            clasificador = 'nada'
        #nombre_archivo = os.path.basename(direcM[i])

        #obtenemos el tamaño de la imagen
        width, height = imgM.size

        #iniciamos nuestros arreglos para los colores
        red = []
        green = []
        blue = []

        #print(imgM)
        #print(imgO)
        for x in range(width):
            for y in range(height):
                if imgM.getpixel((x,y)) == (255,255,255):
                    r, g, b = imgO.getpixel((x, y))
                    red.append(r)
                    green.append(g)
                    blue.append(b)
        # cargar la imagen en una matriz numpy
        img = np.array(Image.open(dirO + str(posOrig) + punto).convert('L'))
        # cargar la máscara en una matriz numpy
        mask = np.array(Image.open(direcM[i]).convert('L'))
        # aplicar la máscara a la imagen
        imgMasked = np.ma.masked_array(img, mask=mask)

        #energia
        # Normalizar los valores de los píxeles
        imgNorm = imgMasked / 255.0
        # Elevar al cuadrado los valores de los píxeles normalizados
        imgNormSq = np.square(imgNorm)
        # Calcular la energía total de la imagen
        energia = np.sum(imgNormSq)

        #varianza
        # calcular la varianza de la imagen en los píxeles que están dentro de la máscara
        variance = np.ma.var(imgNorm)

        # Calcular la desviación estándar de los valores de píxeles
        deviacion = np.std(imgMasked)

        # Calcular el contraste como el valor máximo menos el valor mínimo dividido por la desviación estándar
        contraste= (np.max(imgNorm) - np.min(imgNorm)) / deviacion


        # Crear el histograma de la imagen
        # hist, bins = np.histogram(imgMasked, bins=256)
        mediaRed = np.mean(red)
        mediaGreen = np.mean(green)
        mediaBlue = np.mean(blue)

        #color
        if mediaRed > colorMax:
            colorMax = mediaRed
        if mediaGreen > colorMax:
            colorMax = mediaGreen
        if mediaBlue > colorMax:
            colorMax = mediaBlue
        if mediaRed < colorMini:
            colorMini = mediaRed
        if mediaGreen < colorMini:
            colorMini = mediaGreen
        if mediaBlue < colorMini:
            colorMini = mediaBlue

        #contraste
        if contrMax < contraste:
            contrMax = contraste
        if contrMini > contraste:
            contrMini = contraste
        
        #varianza
        if variaMax < variance:
            variaMax = variance
        if variaMini > variance:
            variaMini = variance

        #energia
        if energMax < energia:
            energMax = energia
        if energMini > energia:
            energMini = energia
        print("la media del rojo es de : " + str(mediaRed))
        print("la media del verde es de : " + str(mediaGreen))
        print("la media del azul es de : " + str(mediaBlue))
        print("la energia total es de : " + str(energia))
        print("el contraste es de : " + str(contraste))
        print("la varianza es de : " + str(variance))
        print("y es de clase : " + str(clasificador))
        print("")
        print("")
print("valores media del color : " + str(colorMax) + " " + str(colorMini))
print("valores media del contraste : " + str(contrMax) + " " + str(contrMini))
print("valores media del varianza : " + str(variaMax) + " " + str(variaMini))
print("valores media del energia : " + str(energMax) + " " + str(energMini))
