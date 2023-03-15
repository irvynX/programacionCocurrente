import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import numpy as np
import scipy as sp
from sklearn.preprocessing import LabelEncoder
import arff
from scipy.io import arff

datatest = arff.loadarff('datosSMOTERandomTest20.arff')
dftest = pd.DataFrame(datatest[0])
dataTraining = arff.loadarff('datosSMOTERandomTraining80.arff')
dfTraining = pd.DataFrame(dataTraining[0])

# crear un objeto LabelEncoder
letest = LabelEncoder()
leTraining = LabelEncoder()

# Dividir los datos en características (X) y etiquetas (y)
xtest = dftest.drop('clasificador', axis=1)
xtest = xtest.apply(letest.fit_transform)
ytest = letest.fit_transform(dftest['clasificador'])

# Dividir los datos en características (X) y etiquetas (y)
xTraining = dfTraining.drop('clasificador', axis=1)
xTraining = xTraining.apply(leTraining.fit_transform)
yTraining = leTraining.fit_transform(dfTraining['clasificador'])

# Dividir los datos en conjuntos de entrenamiento y prueba
# X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=42)


training_accuracy = []
test_accuracy = []
training_error = []
test_error = []

n_depth = range(1, 15)

for depth in n_depth:
    #build the model
    clf = DecisionTreeClassifier(random_state=0, max_depth = depth)
    clf.fit(xTraining, yTraining)
    #y_pred = clf.predict(xtest)
    #record training set accuracy and error
    training_accuracy.append(clf.score(xTraining, yTraining))
    training_error.append(1.0 - clf.score(xTraining, yTraining))
    #record generalization accuracy and error
    test_accuracy.append(clf.score(xtest, ytest))
    test_error.append(1.0 - clf.score(xtest, ytest))
    print(depth - 1,' test error: ', test_error[depth - 1],'training error: ', training_error[depth - 1])
    print('')
    print('')

plt.plot(n_depth, training_error, label="training error")
plt.plot(n_depth, test_error, label="test error")
plt.ylabel("Accuracy")
plt.xlabel("n_depth")
plt.legend()
plt.show()