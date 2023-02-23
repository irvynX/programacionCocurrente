from PIL import Image

# Abre la imagen
img = Image.open("imagen.jpg")

# Obtiene la anchura y altura de la imagen
width, height = img.size

# Itera sobre cada pixel y extrae el valor RGB
for x in range(width):
    for y in range(height):
        r, g, b = img.getpixel((x,y))
        print("Pixel en x=", x, " y=", y, " R=", r, " G=", g, " B=", b)
