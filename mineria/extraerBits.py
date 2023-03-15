from PIL import Image
import statistics
import glob

dirO = "imgO/img"
dirM = "imgM/m"
punto = ".png"
numM = 1
for posOrig in range(1, 2):
    # Abre la imagen original y recupera sus mascaras
    direcO = dirO + str(posOrig) + punto
    direcM = glob.glob(dirM + str(posOrig) + '/*')
    numMascaras = len(direcM)
    imgO = Image.open(direcO).convert("RGB")
    imgM = Image.open(direcM[0]).convert("RGB")
    numM = numM + 1
    direcM = dirM + str(numM) + punto
    imgM2 = Image.open(direcM).convert("RGB")
    numM = numM + 1
    direcM = dirM + str(numM) + punto
    imgM3 = Image.open(direcM).convert("RGB")
    numM = numM + 1
    direcM = dirM + str(numM) + punto
    imgOut1 = Image.new('RGB',(1500,1500),color='black')
    imgOut2 = Image.new('RGB',(1500,1500),color='black')
    imgOut3 = Image.new('RGB',(1500,1500),color='black')
    imgOut4 = Image.new('RGB',(1500,1500),color='black')

    # Obtiene el ancho y el alto de la imagen
    width, height = imgO.size

    # Crea una lista para almacenar los valores de rojo de los píxeles
    red1 = []
    green1 = []
    blue1 = []

    red2 = []
    green2 = []
    blue2 = []

    red3 = []
    green3 = []
    blue3 = []

    red4 = []
    green4 = []
    blue4 = []

    varianza = []
    # Itera sobre todos los píxeles de la imagen y agrega el valor de rojo a la lista
    for y in range(height):
        for x in range(width):
            if imgM1.getpixel((x,y)) == (255,255,255):
                r, g, b = imgO.getpixel((x, y))
                red1.append(r)
                green1.append(g)
                blue1.append(b)
                imgOut1.putpixel((x, y),(r, g, b))
                imgOut2.putpixel((x, y),(0, 0, 0))
                imgOut3.putpixel((x, y),(0, 0, 0))
                imgOut4.putpixel((x, y),(0, 0, 0))
            elif imgM2.getpixel((x,y)) == (255,255,255):
                r, g, b = imgO.getpixel((x, y))
                red2.append(r)
                green2.append(g)
                blue2.append(b)
                imgOut1.putpixel((x, y),(0, 0, 0))
                imgOut2.putpixel((x, y),(r, g, b))
                imgOut3.putpixel((x, y),(0, 0, 0))
                imgOut4.putpixel((x, y),(0, 0, 0))
            elif imgM3.getpixel((x,y)) == (255,255,255):
                r, g, b = imgO.getpixel((x, y))
                red3.append(r)
                green3.append(g)
                blue3.append(b)
                imgOut1.putpixel((x, y),(0, 0, 0))
                imgOut2.putpixel((x, y),(0, 0, 0))
                imgOut3.putpixel((x, y),(r, g, b))
                imgOut4.putpixel((x, y),(0, 0, 0))
            else:
                r, g, b = imgO.getpixel((x, y))
                red4.append(r)
                green4.append(g)
                blue4.append(b)
                imgOut1.putpixel((x, y),(0, 0, 0))
                imgOut2.putpixel((x, y),(0, 0, 0))
                imgOut3.putpixel((x, y),(0, 0, 0))
                imgOut4.putpixel((x, y),(r, g, b))
    print(statistics.variance(red1))
    print(statistics.variance(red2))
    print(statistics.variance(red3))
    print(statistics.variance(red4))
    print(statistics.variance(blue1))
    print(statistics.variance(blue2))
    print(statistics.variance(blue3))
    print(statistics.variance(blue4))
    print(statistics.variance(green1))
    print(statistics.variance(green2))
    print(statistics.variance(green3))
    print(statistics.variance(green4))
    red1 = []
    red2 = []
    red3 = []
    red4 = []
    green1 = []
    green2 = []
    green3 = []
    green4 = []
    blue1 = []
    blue2 = []
    blue3 = []
    blue4 = []
    
    imgOut1.save(str(z) + "salida1.png")
    imgOut2.save(str(z) + "salida2.png")
    imgOut3.save(str(z) + "salida3.png")
    imgOut4.save(str(z) + "salida4.png")

