from PIL import Image

# Abre la imagen
img = Image.open("1.1.png")
imgOut = Image.new('RGB', (830, 469), color='black')


# Obtiene la anchura y altura de la imagen
width, height = img.size

# Verifica si la imagen tiene un canal alfa
if img.mode in ("RGBA", "LA") or (img.mode == "P" and "transparency" in img.info):
    alpha_channel = True
else:
    alpha_channel = False

# Itera sobre cada pixel y extrae el valor RGB
for x in range(width):
    for y in range(height):
        if alpha_channel:
            r, g, b, a = img.getpixel((x,y))
            imgOut.putpixel((x, y), (r, 0, 0))
            #print("Pixel en x=", x, " y=", y, " R=", r, " G=", g, " B=", b, " A=", a)
        else:
            r, g, b = img.getpixel((x,y))
            imgOut.putpixel((x,y), (r, 0, 0))
            #print("Pixel en x=", x, " y=", y, " R=", r, " G=", g, " B=", b)

#guardar imagen
img.save("salida1.png")