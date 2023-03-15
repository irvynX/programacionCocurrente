import csv

# Define los datos
datos = [
    ['Juan', 25],
    ['Maria', 30],
    ['Pedro', 35]
]

# Abre el archivo en modo escritura
with open('ejemplo.csv', mode='w', newline='') as archivo_csv:
    
    # Crea un escritor CSV
    escritor_csv = csv.writer(archivo_csv, delimiter=',')
    
    # Escribe los datos en el archivo CSV
    escritor_csv.writerows(datos)
