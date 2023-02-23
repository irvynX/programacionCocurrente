from PIL import Image

dirO = "imgO/o"
dirM = "imgM/m"
punto = ".png"
numM = 1
for z in range(1, 3):
    # Abre la imagen y conviértela en modo "RGB"
    #img = Image.open("1.3.png").convert("RGB")
    direcO = dirO + str(z) + punto
    direcM = dirM + str(numM) + punto
    imgO = Image.open(direcO).convert("RGB")
    imgM1 = Image.open(direcM).convert("RGB")
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

    # Imprime los valores de rojo de los primeros 10 píxeles
    #print(red_values[:10])
    imgOut1.save(str(z) + "salida1.png")
    imgOut2.save(str(z) + "salida2.png")
    imgOut3.save(str(z) + "salida3.png")
    imgOut4.save(str(z) + "salida4.png")

