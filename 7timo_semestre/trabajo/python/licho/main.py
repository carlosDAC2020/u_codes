import pandas as pd
import numpy as np
from tabulate import tabulate
import seaborn as sns
import matplotlib.pyplot as plt
# para crear un modelo de regresión lineal
from sklearn.linear_model import LinearRegression  
# para calcular el error cuadrático medio
from sklearn.metrics import mean_squared_error   

# Carga la base de datos "Possum"
data = pd.read_csv("possum.csv") 

# Selecciona las columnas específicas para el análisis estadístico
selected_columns = ['hdlngth', 'skullw', 'totlngth', 'taill', 'footlgth', 'earconch', 'eye', 'chest', 'belly']
selected_data = data[selected_columns]


# (1.0 punto) Análisis Estadístico de los datos ---------------------------------------------

"""   
1 Realice un análisis estadístico de las caracterísiticas de la base de datos. 
""" 
def p_1_0_1():

    # Realiza el análisis estadístico
    statistics = selected_data.describe()

    # Convierte los resultados a una tabla
    table = tabulate(statistics, headers='keys', tablefmt='fancy_grid')

    # Imprime la tabla
    print("Análisis estadístico de las variables:")
    print(table)

    # Explicación de las estadísticas
    print("\nDescripción de las estadísticas:")
    print("- count: la cantidad de observaciones no faltantes en cada columna.")
    print("- mean: la media (promedio) de los valores en cada columna.")
    print("- std: la desviación estándar, que mide la dispersión de los valores alrededor de la media.")
    print("- min: el valor mínimo de cada columna.")
    print("- 25%: el percentil 25%, es decir, el valor por debajo del cual cae el 25% de los datos.")
    print("- 50%: el percentil 50% o mediana, que separa los datos en dos partes iguales.")
    print("- 75%: el percentil 75%, es decir, el valor por debajo del cual cae el 75% de los datos.")
    print("- max: el valor máximo de cada columna.")

p_1_0_1()
"""
2. Evalúe la dependencia estadística entre las caracteristicas a través de los los coeficientes de correlación de Pearson. Represente a través
"""
def p_1_0_2():
    # Calcula la matriz de correlación
    correlation_matrix = selected_data.corr()

    # Convierte la matriz de correlación a texto
    correlation_text = correlation_matrix.to_string()

    # Imprime la matriz de correlación en texto
    print("\n Matriz de correlación:")
    print(correlation_text)

    # Genera el diagrama de calor de la matriz de correlación
    plt.figure(figsize=(10, 8))
    sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt=".2f", square=True)
    plt.title("Matriz de Correlación")
    plt.show()

p_1_0_2()

"""
3. Basados en el item 2 seleccione una variable objetivo y1 y dos características diferentes (1, 2) para estimar las variable objetivo.

SOLUCION

Variable objetivo 
    (y1): 'totlngth'
Características 
    (x1): 'skullw'
    (x2): 'chest'
"""
y1 = {
    "var": "totlngth",
    "datos": data['totlngth']
}

x1 = {
    "var": "hdlngth",
    "datos": data['hdlngth']
}

x2 = {
    "var": "skullw",
    "datos": data['skullw']
}
"""
Justificaciones:

1   Correlación fuerte: La variable 'totlngth' (longitud total del cuerpo) tiene una correlación alta con 'skullw' (anchura del cráneo) y 'chest' (longitud del pecho) en la matriz de correlación. Esto sugiere que estas características pueden influir en la longitud total del cuerpo de manera significativa.

2   Contexto biológico: En el contexto de los opossums, es razonable suponer que la anchura del cráneo y la longitud del pecho pueden estar relacionadas con la longitud total del cuerpo. Estas características podrían ser indicadores físicos relevantes para estimar la longitud total.

3   Independencia: Las características 'skullw' y 'chest' tienen una correlación moderada entre sí, pero no es demasiado alta. Aunque hay una relación, aún se consideran independientes para propósitos de regresión lineal univariable.
"""

"""
4. Basados en el item 2 seleccione una variable objetivo y2 y dos características diferentes (3, 4) para estimar las variable objetivo. 

SOLUCION

Variable objetivo 
    (y1): 'belly'
Características 
    (x1): 'hdlngth'
    (x2): 'footlgth'
"""
y2 = {
    "var": "belly",
    "datos": data['belly']
}
x3 = {
    "var": "totlngth",
    "datos": data['totlngth']
}
x4 = {
    "var": "taill",
    "datos": data['taill']
}
"""
Justificaciones:

1   Correlación significativa: La variable 'belly' (circunferencia del vientre) muestra una correlación moderada con 'hdlngth' (longitud de la cabeza) y 'footlgth' (longitud de la pata) en la matriz de correlación. Esto sugiere que estas características pueden ser indicativas de la circunferencia del vientre en los opossums.

2   Relevancia biológica: La longitud de la cabeza y la longitud de la pata podrían ser características físicas que están relacionadas con la circunferencia del vientre en los opossums. Estas medidas pueden influir en la cantidad de tejido adiposo o la distribución de grasa en el cuerpo.

3   Independencia razonable: Aunque hay una correlación moderada entre 'hdlngth' y 'footlgth', la independencia entre estas características se considera razonable para realizar una regresión lineal univariable.
"""

"""
funcion para obtener las regreciones i hacer su correspondiente analisis 


"""
def analisis_de_regreciones(y, xa, xb):

    print("\n   Analisis de regrecion")
    print("Variable objetivo")
    print(f'    {y["var"]} \n')
    
    print("Características")
    print(f'    {xa["var"]}')
    print(f'    {xb["var"]} \n')


    # Regresión lineal y vs xa
    regression1 = LinearRegression()
    regression1.fit(xa["datos"].values.reshape(-1, 1), y["datos"].values.reshape(-1, 1))
    y_pred1 = regression1.predict(xa["datos"].values.reshape(-1, 1))
    

    # Regresión lineal y1 vs x2
    regression2 = LinearRegression()
    regression2.fit(xb["datos"].values.reshape(-1, 1), y["datos"].values.reshape(-1, 1))
    y_pred2 = regression2.predict(xb["datos"].values.reshape(-1, 1))

    print("Calculo del error cuadrático medio y formula de la regrecion cada casos.") 
    mse1 = mean_squared_error(y["datos"], y_pred1)
    print(f'MSE {y["var"]} vs {xa["var"]}', mse1)
    print(' y = {}x + {}'.format(np.round(regression1.coef_[0], 2), np.round(regression1.intercept_, 2)))

    mse2 = mean_squared_error(y["datos"], y_pred2)
    print(f'MSE {y["var"]} vs {xb["var"]}', mse2)
    print(' y = {}x + {}'.format(np.round(regression2.coef_[0], 2), np.round(regression2.intercept_, 2)))

    # Gráfico y1 vs x1 y y1 vs x2
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

    # Gráfico y1 vs x1
    ax1.scatter(xa["datos"], y["datos"], label='Datos reales')
    ax1.plot(xa["datos"], y_pred1, color='red', label='Regresión')
    ax1.set_xlabel('hdlngth')
    ax1.set_ylabel('totlngth')
    ax1.legend()
    ax1.set_title(f'Regresión lineal: {y["var"]} vs {xa["var"]}')

    # Gráfico y1 vs x2
    ax2.scatter(xb["datos"], y["datos"], label='Datos reales')
    ax2.plot(xb["datos"], y_pred2, color='red', label='Regresión')
    ax2.set_xlabel('skullw')
    ax2.set_ylabel('totlngth')
    ax2.legend()
    ax2.set_title(f'Regresión lineal: {y["var"]} vs {xb["var"]}')

    plt.tight_layout()
    plt.show()


"""
(2.0 puntos) Modelo de regresión lineal univariable y₁ (x1), y1(x2) -----------------------------------------------------------
"""
print("\n Modelo de regresión lineal univariable y1(x2), Y1(x2) ")
analisis_de_regreciones(y1,x1,x2)

"""
(2.0 puntos) Modelo de regresión lineal univariable y2(x3), Y2(x4) -----------------------------------------------------------
"""
print("\n Modelo de regresión lineal univariable y2(x3), Y2(x4) ")
analisis_de_regreciones(y2,x3,x4)







