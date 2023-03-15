import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import scipy as sp
from sklearn.preprocessing import LabelEncoder
import arff
from scipy.io import arff


# carga el archivo ARFF
dataset, meta = arff.loadarff('IncendiosTest1.arff')

# imprime el conjunto de datos
print(dataset)

# imprime los metadatos
print(meta)

# Cargar los datos desde el archivo CSV
df = pd.read_csv('DatosIncendios.csv')

# crear un objeto LabelEncoder
le = LabelEncoder()

# ajustar y transformar la columna etiqueta
y = le.fit_transform(df['clasificador'])

# ajustar y transformar las características
x = df.drop('clasificador', axis=1)
x = x.apply(le.fit_transform)


# Dividir los datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)


training_accuracy = []
test_accuracy = []
training_error = []
test_error = []

n_depth = range(1, 10)

for depth in n_depth:
    #build the model
    clf = DecisionTreeClassifier(random_state=0, max_depth = depth)
    clf.fit(X_train, y_train)
    #record training set accuracy and error
    training_accuracy.append(clf.score(X_train, y_train))
    training_error.append(1.0 - clf.score(X_train, y_train))
    #record generalization accuracy and error
    test_accuracy.append(clf.score(X_test, y_test))
    test_error.append(1.0 - clf.score(X_test, y_test))

plt.plot(n_depth, training_accuracy, label="training accuracy")
plt.plot(n_depth, test_accuracy, label="test accuracy")
plt.ylabel("Accuracy")
plt.xlabel("n_depth")
plt.legend()
plt.show()