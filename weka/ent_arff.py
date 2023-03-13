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

datatest = arff.loadarff('IncendiosTest3.arff')
dftest = pd.DataFrame(datatest[0])
dataTraining = arff.loadarff('IncendiosTraining3.arff')
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

n_depth = range(1, 20)

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

plt.plot(n_depth, training_accuracy, label="training accuracy")
plt.plot(n_depth, test_accuracy, label="test accuracy")
plt.ylabel("Accuracy")
plt.xlabel("n_depth")
plt.legend()
plt.show()