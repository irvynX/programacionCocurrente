#librerias
import numpy as np
import cv2 as cv

#cargar imagenes
img = "1.1.png"

#leer imagen
imgColor = cv.imread(img,1)
imgColorB = cv.imread(img,1)
imgColorG = cv.imread(img,1)
imgColorR = cv.imread(img,1)
imgColorN = cv.imread(img,1)

#mostrar imagen
cv.imshow("imgColor",imgColorB)
print("hola mundo")