from PIL import Image
import numpy as np
import cv2

# Cargar la imagen
mat_cargada = np.load('SegmentationClass/img1.npy')
mat_cargada = np.loadtxt('matriz.txt')
print(mat_cargada)
cv2.imshow('Matriz', mat_cargada)
cv2.waitKey(0)
cv2.destroyAllWindows()

