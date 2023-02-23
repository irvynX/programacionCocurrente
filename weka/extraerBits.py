from PIL import Image

# Abre la imagen y conviértela en modo "RGB"
img = Image.open("1.1.png").convert("RGB")
imgOut = image.new('RGB',(830,469),color='black')

# Obtiene el ancho y el alto de la imagen
width, height = img.size

# Crea una lista para almacenar los valores de rojo de los píxeles
red_values = []

# Itera sobre todos los píxeles de la imagen y agrega el valor de rojo a la lista
for y in range(height):
    for x in range(width):
        r, g, b = img.getpixel((x, y))
        red_values.append(r)

i = 0
for y in range(height):
    for x in range(width):
        imgOut.putpixel((x, y),(red values[i], 0, 0))
        i = i + 1
# Imprime los valores de rojo de los primeros 10 píxeles
print(red_values[:10])
imgOut.save("salida1.png")
