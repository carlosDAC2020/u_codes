import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

# Leer los archivos CSV separados por punto y coma
df_train = pd.read_csv("train.csv", sep=";")
df_test = pd.read_csv("test.csv")

print(df_train.info())
print(df_test.info())

# Seleccionar solo las columnas numéricas
numerical_df_train = df_train.select_dtypes(include='number')

# Calcular la matriz de correlación
correlation_matrix = numerical_df_train.corr()

# Visualizar la matriz de correlación con seaborn
plt.figure(figsize=(10, 8))
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', vmin=-1, vmax=1)
plt.title('Matriz de Correlación de Variables Numéricas - df_train')
plt.show()

# Seleccionar las 10 variables con mejor correlación con SalePrice
top_10_features = correlation_matrix['SalePrice'].abs().sort_values(ascending=False).index[1:11]
print("Top 10 features with highest correlation to SalePrice:")
print(top_10_features)

# Crear un nuevo dataframe con las variables seleccionadas
X = numerical_df_train[top_10_features]
y = numerical_df_train['SalePrice']

# Dividir los datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Ajustar el modelo de regresión lineal
model = LinearRegression()
model.fit(X_train, y_train)

# Realizar predicciones
y_pred = model.predict(X_test)

# Calcular métricas de evaluación
mse = mean_squared_error(y_test, y_pred)
rmse = mean_squared_error(y_test, y_pred, squared=False)
mae = mean_absolute_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print("Reporte de Métricas del Modelo:")
print(f"Mean Squared Error (MSE): {mse}")
print(f"Root Mean Squared Error (RMSE): {rmse}")
print(f"Mean Absolute Error (MAE): {mae}")
print(f"R-squared (R²): {r2}")

# Visualizar las predicciones vs los valores reales
plt.figure(figsize=(10, 6))
plt.scatter(y_test, y_pred, alpha=0.7)
plt.xlabel("Actual SalePrice")
plt.ylabel("Predicted SalePrice")
plt.title("Actual vs Predicted SalePrice")
plt.show()
