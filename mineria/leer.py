import csv

# Crea una lista vacía para almacenar los datos del archivo CSV
datos = []

# Abre el archivo en modo lectura
with open('ejemplo.csv', mode='r') as archivo_csv:
    
    # Crea un lector CSV
    lector_csv = csv.reader(archivo_csv, delimiter=',')
    
    # Lee los datos del archivo CSV y los agrega a la lista
    for fila in lector_csv:
        datos.append(fila)

# Muestra los datos almacenados en la lista
print(datos[1])
