from PIL import Image

# Abre la imagen y conviértela en modo "RGB"
#img = Image.open("1.3.png").convert("RGB")
img = Image.open("imgP/m2.png").convert("RGB")
imgOut = Image.new('RGB',(1500,1500),color='black')

# Obtiene el ancho y el alto de la imagen
width, height = img.size

# Crea una lista para almacenar los valores de rojo de los píxeles
red_values = []

# Itera sobre todos los píxeles de la imagen y agrega el valor de rojo a la lista
i = 0
for y in range(height):
    for x in range(width):
        r, g, b = img.getpixel((x, y))
        red_values.append(r)
        print(x,y,r,g,b)
        imgOut.putpixel((x, y),(r, g, b))
        i = i + 1

# Imprime los valores de rojo de los primeros 10 píxeles
#print(red_values[:10])
imgOut.save("salida1.png")
