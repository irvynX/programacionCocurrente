from PIL import Image
import statistics
import glob
import numpy as np
import os
import cv2
import arff
import csv

datos = []
datosTemporal = []

# mascara amarilla = 128,128,0 (no incendio)
# mascara roja = 128,0,0 (incendio)
# mascara verde = 0,128,0 (humo)

#variables de los descriptores
variaMini = 99999999.0
contrMini = 99999999.0
colorMini = 99999999.0
energMini = 99999999.0
desviMini = 99999999.0
variaMax = 0.0
contrMax = 0.0
colorMax = 0.0
energMax = 0.0
desviMax = 0.0

carpetaOriginal = "imgO"
carpetaMascara = "imgM"
#dirOrig = glob.glob('imgO/*')
dirOrig = glob.glob(carpetaOriginal + '/*.png')

for i in range(0, len(dirOrig)):
    #variables de mascara
    incendio = False
    humo = False
    noIncendio = False

    #iniciamos nuestros arreglos para los colores
    redIncendio = []
    greenIncendio = []
    blueIncendio = []
    redHumo = []
    greenHumo = []
    blueHumo = []
    redNoIncendio = []
    greenNoIncendio = []
    blueNoIncendio = []

    nomArvhivo = os.path.basename(dirOrig[i])
    print(nomArvhivo)
    imgO = Image.open(dirOrig[i]).convert("RGB")
    imgL = Image.open(dirOrig[i]).convert("L")
    imgM = Image.open(carpetaMascara + '/' + nomArvhivo).convert("RGB")

    width, height = imgO.size

    #matriz para num py
    maskIncendio = []
    maskHumo = []
    maskNoIncendio = []

    for x in range(width):
        for y in range(height):
            #mascara roja
            if imgM.getpixel((x,y)) == (128,0,0):
                maskIncendio.append(imgL.getpixel((x,y)))
                if incendio == False:
                    incendio = True
                r, g, b = imgO.getpixel((x, y))
                redIncendio.append(r)
                greenIncendio.append(g)
                blueIncendio.append(b)
            #mascara verde
            if imgM.getpixel((x,y)) == (0,128,0):
                maskHumo.append(imgL.getpixel((x,y)))
                if noIncendio == False:
                    noIncendio = True
                r, g, b = imgO.getpixel((x, y))
                redNoIncendio.append(r)
                greenNoIncendio.append(g)
                blueNoIncendio.append(b)
            #mascara amarilla
            if imgM.getpixel((x, y)) == (128,128,0):
                maskNoIncendio.append(imgL.getpixel((x,y)))
                if humo == False:
                    humo = True
                r, g, b = imgO.getpixel((x, y))
                redHumo.append(r)
                greenHumo.append(g)
                blueHumo.append(b)

    if(incendio == True):
        datosTemporal = []
        maskArray = maskIncendio
        maskT = np.array(maskArray)
        #energia
        # Normalizar los valores de los píxeles
        imgNorm = maskT / 255.0
        # Elevar al cuadrado los valores de los píxeles normalizados
        imgNormSq = np.square(imgNorm)
        # Calcular la energía total de la imagen
        energia = np.sum(imgNormSq)

        #varianza
        # calcular la varianza de la imagen en los píxeles que están dentro de la máscara
        variance = statistics.variance(imgNorm)
        
        # Calcular la desviación estándar de los valores de píxeles
        desviacion = statistics.stdev(maskArray)
        desviacionR = statistics.stdev(redIncendio)
        desviacionG = statistics.stdev(greenIncendio)
        desviacionB = statistics.stdev(blueIncendio)
        

        # Calcular el contraste como el valor máximo menos el valor mínimo dividido por la desviación estándar
        contraste= (np.max(imgNorm) - np.min(imgNorm)) / desviacion

        #meia
        mediaR = statistics.mean(redIncendio)
        mediaG = statistics.mean(greenIncendio)
        mediaB = statistics.mean(blueIncendio)

        """if (colorMini > mediaR):
            colorMini = mediaR
        if (colorMini > mediaG):
            colorMini = mediaG
        if (colorMini > mediaB):
            colorMini = mediaB

        if (colorMax < mediaR):
            colorMax = mediaR
        if (colorMax < mediaG):
            colorMax = mediaG
        if (colorMax < mediaB):
            colorMax = mediaB

        if (variaMini > variance):
            variaMini = variance
        if (contrMini > contraste):
            contrMini = contraste
        if (energMini > energia):
            energMini = energia
        if (desviMini > desviacionR):
            desviMini = desviacionR
        if (desviMini > desviacionG):
            desviMini = desviacionG
        if (desviMini > desviacionB):
            desviMini = desviacionB

        if (variaMax < variance):
            variaMax = variance
        if (contrMax < contraste):
            contrMax = contraste
        if (energMax < energia):
            energMax = energia
        if (desviMax < desviacionR):
            desviMax = desviacionR
        if (desviMax < desviacionG):
            desviMax = desviacionG
        if (desviMax < desviacionB):
            desviMax = desviacionB"""

        #guardamos datos
        if (mediaR <= 85):
            datosTemporal.append('bajo')
        if (mediaR > 85 and mediaR < 170):
            datosTemporal.append('medio')
        if (mediaR >= 170):
            datosTemporal.append('alto')

        if (mediaG <= 85):
            datosTemporal.append('bajo')
        if (mediaG > 85 and mediaG < 170):
            datosTemporal.append('medio')
        if (mediaG >= 170):
            datosTemporal.append('alto')

        if (mediaB <= 85):
            datosTemporal.append('bajo')
        if (mediaB > 85 and mediaB < 170):
            datosTemporal.append('medio')
        if (mediaB >= 170):
            datosTemporal.append('alto')

        if (desviacionR <= 28):
            datosTemporal.append('bajo')
        if (desviacionR > 28 and desviacionR < 50):
            datosTemporal.append('medio')
        if (desviacionR >= 50):
            datosTemporal.append('alto')
            
        if (desviacionG <= 28):
            datosTemporal.append('bajo')
        if (desviacionG > 28 and desviacionG < 50):
            datosTemporal.append('medio')
        if (desviacionG >= 50):
            datosTemporal.append('alto')

        if (desviacionB <= 28):
            datosTemporal.append('bajo')
        if (desviacionB > 28 and desviacionB < 50):
            datosTemporal.append('medio')
        if (desviacionB >= 50):
            datosTemporal.append('alto')
        
        if (energia <= 100000):
            datosTemporal.append('bajo')
        if (energia > 100000 and energia < 200000):
            datosTemporal.append('medio')
        if (energia >= 200000):
            datosTemporal.append('alto')

        if (contraste <= 0.030):
            datosTemporal.append('bajo')
        if (contraste > 0.030 and contraste < 0.045):
            datosTemporal.append('medio')
        if (contraste >= 0.045):
            datosTemporal.append('alto')

        if (variance <= 0.01672):
            datosTemporal.append('bajo')
        if (variance > 0.01672 and variance < 0.03249):
            datosTemporal.append('medio')
        if (variance >= 0.03249):
            datosTemporal.append('alto')

        #mascara roja
        datosTemporal.append('incendio')

        datos.append(datosTemporal)

        """
        print("la media del rojo es de : " + str(mediaR))
        print("la media del verde es de : " + str(mediaG))
        print("la media del azul es de : " + str(mediaB))
        print("la energia total es de : " + str(energia))
        print("la desviacion es de : " + str(desviacion))
        print("el contraste es de : " + str(contraste))
        print("la varianza es de : " + str(variance))
        print("y es de clase : Incendio")
        print("")
        print("")
        """

    if(noIncendio == True):
        datosTemporal = []
        maskArray = maskNoIncendio
        maskT = np.array(maskArray)
        #energia
        # Normalizar los valores de los píxeles
        imgNorm = maskT / 255.0
        # Elevar al cuadrado los valores de los píxeles normalizados
        imgNormSq = np.square(imgNorm)
        # Calcular la energía total de la imagen
        energia = np.sum(imgNormSq)

        #varianza
        # calcular la varianza de la imagen en los píxeles que están dentro de la máscara
        variance = statistics.variance(imgNorm)
        
        # Calcular la desviación estándar de los valores de píxeles
        desviacion = statistics.stdev(maskArray)
        desviacionR = statistics.stdev(redNoIncendio)
        desviacionG = statistics.stdev(greenNoIncendio)
        desviacionB = statistics.stdev(blueNoIncendio)
        

        # Calcular el contraste como el valor máximo menos el valor mínimo dividido por la desviación estándar
        contraste= (np.max(imgNorm) - np.min(imgNorm)) / desviacion

        #meia
        mediaR = statistics.mean(redHumo)
        mediaG = statistics.mean(greenHumo)
        mediaB = statistics.mean(blueHumo)

        """if (colorMini > mediaR):
            colorMini = mediaR
        if (colorMini > mediaG):
            colorMini = mediaG
        if (colorMini > mediaB):
            colorMini = mediaB

        if (colorMax < mediaR):
            colorMax = mediaR
        if (colorMax < mediaG):
            colorMax = mediaG
        if (colorMax < mediaB):
            colorMax = mediaB

        if (variaMini > variance):
            variaMini = variance
        if (contrMini > contraste):
            contrMini = contraste
        if (energMini > energia):
            energMini = energia
        if (desviMini > desviacionR):
            desviMini = desviacionR
        if (desviMini > desviacionG):
            desviMini = desviacionG
        if (desviMini > desviacionB):
            desviMini = desviacionB

        if (variaMax < variance):
            variaMax = variance
        if (contrMax < contraste):
            contrMax = contraste
        if (energMax < energia):
            energMax = energia
        if (desviMax < desviacionR):
            desviMax = desviacionR
        if (desviMax < desviacionG):
            desviMax = desviacionG
        if (desviMax < desviacionB):
            desviMax = desviacionB"""

        #guardamos datos
        if (mediaR <= 85):
            datosTemporal.append('bajo')
        if (mediaR > 85 and mediaR < 170):
            datosTemporal.append('medio')
        if (mediaR >= 170):
            datosTemporal.append('alto')
            
        if (mediaG <= 85):
            datosTemporal.append('bajo')
        if (mediaG > 85 and mediaG < 170):
            datosTemporal.append('medio')
        if (mediaG >= 170):
            datosTemporal.append('alto')

        if (mediaB <= 85):
            datosTemporal.append('bajo')
        if (mediaB > 85 and mediaB < 170):
            datosTemporal.append('medio')
        if (mediaB >= 170):
            datosTemporal.append('alto')

        if (desviacionR <= 28):
            datosTemporal.append('bajo')
        if (desviacionR > 28 and desviacionR < 50):
            datosTemporal.append('medio')
        if (desviacionR >= 50):
            datosTemporal.append('alto')
            
        if (desviacionG <= 28):
            datosTemporal.append('bajo')
        if (desviacionG > 28 and desviacionG < 50):
            datosTemporal.append('medio')
        if (desviacionG >= 50):
            datosTemporal.append('alto')

        if (desviacionB <= 28):
            datosTemporal.append('bajo')
        if (desviacionB > 28 and desviacionB < 50):
            datosTemporal.append('medio')
        if (desviacionB >= 50):
            datosTemporal.append('alto')
        
        if (energia <= 100000):
            datosTemporal.append('bajo')
        if (energia > 100000 and energia < 200000):
            datosTemporal.append('medio')
        if (energia >= 200000):
            datosTemporal.append('alto')

        if (contraste <= 0.030):
            datosTemporal.append('bajo')
        if (contraste > 0.030 and contraste < 0.045):
            datosTemporal.append('medio')
        if (contraste >= 0.045):
            datosTemporal.append('alto')

        if (variance <= 0.01672):
            datosTemporal.append('bajo')
        if (variance > 0.01672 and variance < 0.03249):
            datosTemporal.append('medio')
        if (variance >= 0.03249):
            datosTemporal.append('alto')

        #mascara amarilla
        datosTemporal.append('no incendio')

        datos.append(datosTemporal)
        """
        print("la media del rojo es de : " + str(mediaR))
        print("la media del verde es de : " + str(mediaG))
        print("la media del azul es de : " + str(mediaB))
        print("la energia total es de : " + str(energia))
        print("la desviacion es de : " + str(desviacion))
        print("el contraste es de : " + str(contraste))
        print("la varianza es de : " + str(variance))
        print("y es de clase : No incendio")
        print("")
        print("")
        """

    if(humo == True):
        datosTemporal = []
        maskArray = maskHumo
        maskT = np.array(maskArray)
        #energia
        # Normalizar los valores de los píxeles
        imgNorm = maskT / 255.0
        # Elevar al cuadrado los valores de los píxeles normalizados
        imgNormSq = np.square(imgNorm)
        # Calcular la energía total de la imagen
        energia = np.sum(imgNormSq)

        #varianza
        # calcular la varianza de la imagen en los píxeles que están dentro de la máscara
        variance = statistics.variance(imgNorm)
        
        # Calcular la desviación estándar de los valores de píxeles
        desviacion = statistics.stdev(maskArray)
        desviacionR = statistics.stdev(redHumo)
        desviacionG = statistics.stdev(greenHumo)
        desviacionB = statistics.stdev(blueHumo)
        

        # Calcular el contraste como el valor máximo menos el valor mínimo dividido por la desviación estándar
        contraste= (np.max(imgNorm) - np.min(imgNorm)) / desviacion

        #meia
        mediaR = statistics.mean(redHumo)
        mediaG = statistics.mean(greenHumo)
        mediaB = statistics.mean(blueHumo)

        """if (colorMini > mediaR):
            colorMini = mediaR
        if (colorMini > mediaG):
            colorMini = mediaG
        if (colorMini > mediaB):
            colorMini = mediaB

        if (colorMax < mediaR):
            colorMax = mediaR
        if (colorMax < mediaG):
            colorMax = mediaG
        if (colorMax < mediaB):
            colorMax = mediaB

        if (variaMini > variance):
            variaMini = variance
        if (contrMini > contraste):
            contrMini = contraste
        if (energMini > energia):
            energMini = energia
        if (desviMini > desviacionR):
            desviMini = desviacionR
        if (desviMini > desviacionG):
            desviMini = desviacionG
        if (desviMini > desviacionB):
            desviMini = desviacionB

        if (variaMax < variance):
            variaMax = variance
        if (contrMax < contraste):
            contrMax = contraste
        if (energMax < energia):
            energMax = energia
        if (desviMax < desviacionR):
            desviMax = desviacionR
        if (desviMax < desviacionG):
            desviMax = desviacionG
        if (desviMax < desviacionB):
            desviMax = desviacionB"""

        #guardamos datos
        if (mediaR <= 85):
            datosTemporal.append('bajo')
        if (mediaR > 85 and mediaR < 170):
            datosTemporal.append('medio')
        if (mediaR >= 170):
            datosTemporal.append('alto')
            
        if (mediaG <= 85):
            datosTemporal.append('bajo')
        if (mediaG > 85 and mediaG < 170):
            datosTemporal.append('medio')
        if (mediaG >= 170):
            datosTemporal.append('alto')

        if (mediaB <= 85):
            datosTemporal.append('bajo')
        if (mediaB > 85 and mediaB < 170):
            datosTemporal.append('medio')
        if (mediaB >= 170):
            datosTemporal.append('alto')

        if (desviacionR <= 28):
            datosTemporal.append('bajo')
        if (desviacionR > 28 and desviacionR < 50):
            datosTemporal.append('medio')
        if (desviacionR >= 50):
            datosTemporal.append('alto')
            
        if (desviacionG <= 28):
            datosTemporal.append('bajo')
        if (desviacionG > 28 and desviacionG < 50):
            datosTemporal.append('medio')
        if (desviacionG >= 50):
            datosTemporal.append('alto')

        if (desviacionB <= 28):
            datosTemporal.append('bajo')
        if (desviacionB > 28 and desviacionB < 50):
            datosTemporal.append('medio')
        if (desviacionB >= 50):
            datosTemporal.append('alto')
        
        if (energia <= 100000):
            datosTemporal.append('bajo')
        if (energia > 100000 and energia < 200000):
            datosTemporal.append('medio')
        if (energia >= 200000):
            datosTemporal.append('alto')

        if (contraste <= 0.030):
            datosTemporal.append('bajo')
        if (contraste > 0.030 and contraste < 0.045):
            datosTemporal.append('medio')
        if (contraste >= 0.045):
            datosTemporal.append('alto')

        if (variance <= 0.01672):
            datosTemporal.append('bajo')
        if (variance > 0.01672 and variance < 0.03249):
            datosTemporal.append('medio')
        if (variance >= 0.03249):
            datosTemporal.append('alto')

        #mascar verde
        datosTemporal.append('humo')

        datos.append(datosTemporal)
        """
        print("la media del rojo es de : " + str(mediaR))
        print("la media del verde es de : " + str(mediaG))
        print("la media del azul es de : " + str(mediaB))
        print("la energia total es de : " + str(energia))
        print("la desviacion es de : " + str(desviacion))
        print("el contraste es de : " + str(contraste))
        print("la varianza es de : " + str(variance))
        print("y es de clase : Humo")
        print("")
        print("")
        """

"""print("valores media del color : " + str(colorMax) + " " + str(colorMini))
print("valores media del contraste : " + str(contrMax) + " " + str(contrMini))
print("valores media del varianza : " + str(variaMax) + " " + str(variaMini))
print("valores media del energia : " + str(energMax) + " " + str(energMini))
print("valores media de la desviacion : " + str(desviMax) + " " + str(desviMini))"""
# Creamos el archivo CSV
with open('datos.csv', 'w', newline='') as f:
    writer = csv.writer(f)
    writer.writerows(datos)