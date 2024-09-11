import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from sklearn.ensemble import RandomForestClassifier
import numpy as np

# Leer los archivos CSV separados por punto y coma
df_train = pd.read_csv("train.csv", sep=";")
df_test = pd.read_csv("test.csv")

# Crear el codificador para la variable dependiente
label_encoder = LabelEncoder()

# Ajustar y transformar los datos de la columna 'MSZoning' y almacenarlos en una nueva columna
df_train['MSZoning_encoded'] = label_encoder.fit_transform(df_train['MSZoning'])
# Mostrar los primeros registros para verificar
print(df_train[['MSZoning', 'MSZoning_encoded']][:30])

# Recorrer todas las columnas del DataFrame df_train
for col in df_train.columns:
    # Verificar si la columna es de tipo objeto (categórica) y no ha sido codificada previamente
    if df_train[col].dtype == 'object' and col != 'MSZoning':
        # Aplicar codificación numérica a las categorías
        df_train[col] = label_encoder.fit_transform(df_train[col])


# Obtener la proporción de cada categoría en la columna 'MSZoning'
category_counts = df_train['MSZoning'].value_counts()
category_labels = category_counts.index
category_sizes = category_counts.values

# Crear el gráfico de pastel
plt.figure(figsize=(8, 6))
plt.pie(category_sizes, labels=category_labels, autopct='%1.1f%%', startangle=140)
plt.title('Proporción de Categorías en MSZoning')
plt.axis('equal')  # Para asegurar que el pastel sea un círculo
plt.show()

# Seleccionar las variables independientes (features) y la variable dependiente (target)
X = df_train.drop(columns=['MSZoning', 'MSZoning_encoded'])
y = df_train['MSZoning_encoded']

# Convertir variables categóricas en variables numéricas usando codificación one-hot
X_encoded = pd.get_dummies(X)

# Crear un modelo de Random Forest
rf_model = RandomForestClassifier()

# Ajustar el modelo a los datos
rf_model.fit(X_encoded, y)

# Obtener la importancia de las características
importances = rf_model.feature_importances_
indices = np.argsort(importances)[::-1]

# Visualizar la importancia de las características
plt.figure(figsize=(12, 8))
plt.title("Importancia de las Características")
plt.bar(range(X_encoded.shape[1]), importances[indices], align="center")
plt.xticks(range(X_encoded.shape[1]), X_encoded.columns[indices], rotation=90)
plt.show()

# Mostrar las características más importantes
important_features = X_encoded.columns[indices]
print("Características ordenadas por importancia:")
print(important_features)

# Seleccionar las características más importantes (por ejemplo, las 10 principales)
top_features = important_features[:10]
X_final = X_encoded[top_features]

# Dividir los datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X_final, y, test_size=0.2, random_state=42)

# Crear el modelo de regresión logística
logistic_model = LogisticRegression(max_iter=200)

# Ajustar el modelo a los datos de entrenamiento
logistic_model.fit(X_train, y_train)

# Realizar predicciones en el conjunto de prueba
y_pred = logistic_model.predict(X_test)

# Evaluar el rendimiento del modelo
accuracy = accuracy_score(y_test, y_pred)
conf_matrix = confusion_matrix(y_test, y_pred)
class_report = classification_report(y_test, y_pred, target_names=label_encoder.classes_)

print(f"Accuracy: {accuracy}")
print("Confusion Matrix:")
print(conf_matrix)
print("Classification Report:")
print(class_report)
