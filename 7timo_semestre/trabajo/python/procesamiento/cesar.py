
# NOTA 
# lenguaje Python 3.11.1
# las librerias utilizadas deben ser instaladas a traves de pip ya q no son nativas de pyytho

# para trabajar con arrays y operaciones matemáticas
import numpy as np   
# para trabajar con dataframes y leer archivos csv     
import pandas as pd           
# para crear gráficas    
import matplotlib.pyplot as plt   
# para crear un modelo de regresión lineal
from sklearn.linear_model import LinearRegression  
 # para crear características polinómicas
from sklearn.preprocessing import PolynomialFeatures 
 # para calcular el error cuadrático medio
from sklearn.metrics import mean_squared_error 


# lectura y clasioficacion de los datos ------------------------------------------------------
# Leer los datos desde el archivo CSV
df = pd.read_csv('datos.csv', sep=';')
voltaje = df["voltaje"]
potencia = df["potencia "]

# obtencion de los modelos de regrecion -----------------------------------------------------

# Crear un objeto de regresión lineal y ajustar los datos de entrada y salida
reg_lineal = LinearRegression()
reg_lineal.fit(voltaje.values.reshape(-1, 1), potencia)

# Crear un objeto de características polinómicas y transformar las horas de entrada
poly = PolynomialFeatures(degree=2)
voltaje_poly = poly.fit_transform(voltaje.values.reshape(-1, 1))

# Crear un objeto de regresión polinómica y ajustar los datos de entrada y salida transformados
reg_poly = LinearRegression()
reg_poly.fit(voltaje_poly, potencia)

# Obtencion de estadisticos 
# Calcular la desviación estándar total y el error estándar del estimado
std_total = np.std(potencia)
error_estimado = np.sqrt(mean_squared_error(potencia, reg_lineal.predict(voltaje.values.reshape(-1, 1))))

# Calcular el coeficiente de correlación y el coeficiente de determinación
coef_corr = np.corrcoef(voltaje, potencia)[0, 1]
coef_det_lin = reg_lineal.score(voltaje.values.reshape(-1, 1), potencia)
coef_det_poly = reg_poly.score(voltaje_poly, potencia)

# Imprimir los resultados
print("Desviacion estandar total: {:.2f}".format(std_total))
print("Error estandar del estimado: {:.2f}".format(error_estimado))
print("Coeficiente de correlacion: {:.2f}".format(coef_corr))
print("Coeficiente de determinacion (lineal): {:.2f}".format(coef_det_lin))
print("Coeficiente de determinacion (polinomico): {:.2f}".format(coef_det_poly))

# crear una figura con dos subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

# graficar la regresión lineal 
ax1.scatter(voltaje, potencia, color='blue')
ax1.plot(voltaje, reg_lineal.predict(voltaje.values.reshape(-1, 1)), color='red')
ax1.set_xlabel('voltaje')
ax1.set_ylabel('Potencia')
ax1.text(0.1, 0.9, ' y = {}x + {}'.format(round(reg_lineal.coef_[0], 2), round(reg_lineal.intercept_, 2)), transform=ax1.transAxes)
ax1.set_title('Regresión lineal')


# graficar la regresión polinómica
ax2.scatter(voltaje, potencia, color='blue')
ax2.plot(voltaje, reg_poly.predict(voltaje_poly), color='green')
ax2.set_xlabel('voltaje')
ax2.set_ylabel('Potencia')
ax2.set_title('Regresión polinómica')
ax2.text(0.1, 0.9, ' y = {}x^2 + {}x + {}'.format(round(reg_poly.coef_.reshape(1, -1)[0][2], 2), round(reg_poly.coef_.reshape(1, -1)[0][1], 2), round(reg_poly.coef_.reshape(1, -1)[0][0], 2)), transform=ax2.transAxes)

plt.show()

