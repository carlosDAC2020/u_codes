import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from collections import Counter
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.metrics import classification_report
from imblearn.over_sampling import SMOTE


df = pd.read_csv("training_data.csv")
# parte 1  analisis de dataset -------------------------------------
print("\n informacion general del dataset")
print(df.info())
df = df.drop('#', axis=1)


# parte 2 manejo de variables categoricas -------------------------
# Obtener los valores únicos de las columnas de tipo objeto
protocolo = df["proto"].unique()
service = df["service"].unique()
attack_types = df['Attack_type'].unique()

# Imprimir protocolos con identificadores
print("-"*46)
print("|{:^12}|{:^15}|{:^12}|".format("protocolo","id_protocolo","cant_val"))
print("-"*43)
idp = 1
cant_vals_p=0
for p in protocolo:
    print("|{:^12}|{:^15}|{:^12}|".format(p, idp, len(df[df["proto"] == p])))
    idp += 1
    cant_vals_p+=len(df[df["proto"] == p])
print("-"*43)
print("cant valores:", cant_vals_p)

# Imprimir servicios con identificadores
print("-"*46)
print("|{:^15}|{:^15}|{:^12}|".format("servicio","id_servicio","cant_val"))
print("-"*46)
ids=1
cant_vals_s=0
for s in service:
    print("|{:^15}|{:^15}|{:^12}|".format(s, ids, len(df[df["service"] == s])))
    ids+=1
    cant_vals_s+=len(df[df["service"] == s])
print("-"*46)
print("cant valores:", cant_vals_s)

# Imprimir tipos de ataques con identificadores
print("-"*57)
print("|{:^29}|{:^12}|{:^12}|".format("ripos de ataque","id_ataque","cant_val"))
print("-"*57)
idat=1
cant_vals_at=0
for at in attack_types:
    print("|{:^29}|{:^12}|{:^12}|".format(at, idat, len(df[df["Attack_type"] == at])))
    idat+=1
    cant_vals_at+=len(df[df["Attack_type"] == at])
print("-"*57)
print("cant valores:", cant_vals_at)

# añadimos 3 columnas nuevas en el dataset para agregar el id segun el protocolo servicio o tipo de ataque 
df['proto_id'] = df['proto'].apply(lambda x: np.where(protocolo == x)[0][0] + 1)
df['service_id'] = df['service'].apply(lambda x: np.where(service == x)[0][0] + 1)
df['attack_type_id'] = df['Attack_type'].apply(lambda x: np.where(attack_types == x)[0][0] + 1)

# Verificar los cambios
print(df[:10])
print(df.info())
# parte 3 seleccion de variable objetivo ----------------------------------

# se selecciona co o variable objetivo attack_type_id para la regrecion logistoca 

# como se distribuyen la cantidad de valores por categoria en la viable attack_type

# Generar datos sintéticos para equilibrar las clases
X = df.select_dtypes(include=[np.number]).drop(columns=['attack_type_id']).values
Y = df['attack_type_id'].values

smote = SMOTE(random_state=42)
X_resampled, Y_resampled = smote.fit_resample(X, Y)

# Verificar el balance de clases después de aplicar SMOTE
print("Balance de clases después de SMOTE:", Counter(Y_resampled))


# parte 5 deficnion de regresion logistica ---------------------------------

sorted(Counter(Y).items())

# Dividir los datos en conjuntos de entrenamiento y prueba
x_train, x_test, y_train, y_test = train_test_split(X_resampled, Y_resampled, test_size=0.3, random_state=3)
print("x_train", x_train.shape)
print("x_test", x_test.shape)
print("y_train", y_train.shape)
print("y_test", y_test.shape)


# min-max normalization
x_train_max =np.max(x_train)
x_train_min =np.min(x_train)
X_train= (x_train - x_train_min)/(x_train_max-x_train_min)
X_test= (x_test - x_train_min)/(x_train_max-x_train_min)

lr = LogisticRegression()
lr.fit(x_train, y_train)

y_pred = lr.predict(x_test)

accuracy = accuracy_score(y_test, y_pred, normalize=False)
print("acuracy:",accuracy)

cm = confusion_matrix(y_test, y_pred)
plt.figure()
sns.heatmap(cm , annot =False, linewidth=0.8,fmt=".1f")
plt.title('Logistic Regression')
plt.show()

print(classification_report(y_test, y_pred))

