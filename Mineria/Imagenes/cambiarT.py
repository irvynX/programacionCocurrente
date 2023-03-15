from PIL import Image
import glob

# Abrir imagen
imgN = glob.glob('imagenes/*')
num = len(imgN)
j = 0

for i in range(0, num):
    print(i)
    img = Image.open(imgN[i]).convert("RGB")
    nueva_imagen = img.resize((900, 900))

    #Guardar imagen redimensionada
    nueva_imagen.save('img' + str(i) + '.png')

#dasd
