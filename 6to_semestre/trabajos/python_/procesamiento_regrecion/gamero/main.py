# para trabajar con arrays y operaciones matemáticas
import numpy as np           
# para trabajar con dataframes y leer archivos csv     
import pandas as pd   
# para porder usar graficas 
import matplotlib.pyplot as plt 
# nos ayuda a encontra el polinomia de lagrange
from scipy.interpolate import lagrange 


def r_lineal(x, y, name_x, name_y):
    # regrecion lineal
    n = len(x)
    sx, sy, sxy, sx2 = np.sum(x), np.sum(y), np.sum(x * y), np.sum(x**2)
    xm, ym = np.mean(x), np.mean(y)
    a1 = (n * sxy - sx * sy) / (n * sx2 - sx**2)
    a0 = ym - a1 * xm

    # formula de la regrecion
    reg = lambda x: a0 + (a1 * x)

    # cálculo de los estadísticos
        # desviación estándar total
    sst = np.sum((y - ym)**2)
    std_dev = np.sqrt(sst / (n - 1))
        # error estándar del estimado
    se = np.sqrt(np.sum((y - reg(x))**2) / (n - 2))
        # coeficiente de correlación
    r = (n * sxy - sx * sy) / np.sqrt((n * sx2 - sx**2) * (n * np.sum(y**2) - sy**2))
        # coeficiente de determinación
    r2 = r**2
    print(f"\n La regresion lineal es \n  y={round(a0, 6)}+{round(a1, 6)}x")
    print(f" Desviación estándar total: {round(std_dev, 6)}")
    print(f" Error estándar del estimado: {round(se, 6)}")
    print(f" Coeficiente de correlación: {round(r, 6)}")
    print(f" Coeficiente de determinación: {round(r2, 6)}")

    

    x_reg = np.linspace(min(x), max(x), 100)

    plt.scatter(x, y, label='Datos')
    plt.plot(x_reg, reg(x_reg), label='Regresión lineal')
    plt.xlabel(name_x)
    plt.ylabel(name_y)
    plt.title('Regresión lineal')
    plt.legend()
    plt.show()


def r_poli_g_2(x, y, name_x, name_y):
    # Regresión polinomial por Mínimos cuadrados
    n = len(x)
    sx = np.sum(x)
    sx2 = np.sum(x**2)
    sx3 = np.sum(x**3)
    sx4 = np.sum(x**4)
    sy = np.sum(y)
    sxy = np.sum(x*y)
    sx2y = np.sum(x**2*y)

    determinante = n*(sx2*sx4-sx3**2)-sx*(sx*sx4-sx3*sx2)+sx2*(sx*sx3-sx2**2)

    determinante_a0 = sy*(sx2*sx4-sx3**2)-sx*(sxy*sx4-sx3*sx2y)+sx2*(sxy*sx3-sx2y*sx2)

    determinante_a1 = n*(sxy*sx4-sx3*sx2y)-sy*(sx*sx4-sx3*sx2)+sx2*(sx*sx2y-sxy*sx2)

    determinante_a2 = n*(sx2*sx2y-sxy*sx3)-sx*(sx*sx2y-sxy*sx2)+sy*(sx*sx3-sx2**2)

    a0 = determinante_a0/determinante
    a1 = determinante_a1/determinante
    a2 = determinante_a2/determinante

    # formula de la regrecion 
    reg = lambda x: a0 + (a1*x) + (a2*(x**2))

    # Cálculo de los residuos y el error estándar del estimado (SEE)
    y_pred = a0 + (a1*x) + (a2*(x**2))
    residuos = y - y_pred
    SEE = np.sqrt(np.sum(residuos**2)/(n-3))

    # Cálculo de la desviación estándar total (SST)
    SST = np.sum((y - np.mean(y))**2)

    # Cálculo del coeficiente de correlación (r)
    r = np.sum((x - np.mean(x))*(y - np.mean(y))) / np.sqrt(np.sum((x - np.mean(x))**2)*np.sum((y - np.mean(y))**2))

    # Cálculo del coeficiente de determinación (R^2)
    R2 = r**2

    print(f"\n La regresión polinomial grado 2 es \n y = {a0}+{a1}x+{a2}x**2")
    print(f" La desviación estándar total (SST) es: {SST:.4f}")
    print(f" El error estándar del estimado (SEE) es: {SEE:.4f}")
    print(f" El coeficiente de correlación (r) es: {r:.4f}")
    print(f" El coeficiente de determinación (R^2) es: {R2:.4f}")

    
    # puntos a evaluar en la grafica 
    x_reg = np.linspace(min(x), max(x), 100)

    # Graficación de los datos y la regrecion polinomica
    plt.scatter(x, y, label='Datos')
    plt.plot(x_reg, reg(x_reg), label='Regresión polinomial de grado 2')
    plt.xlabel(name_x)
    plt.ylabel(name_y)
    plt.title('Regresión polinomial')
    plt.legend()
    plt.show()



def poli_lagrange(x, y, name_x, name_y):
    x = x.tolist()
    y = y.tolist()
    # Encontrar la regresión polinómica
    polinomio = np.poly1d(np.polyfit(x, y, len(x)-1))
    print("\n\n Fórmula del polinomio de lagrange: ")
    print(" y = ",polinomio)

    # Puntos a evaluar en la grafica 
    x_reg = np.linspace(min(x), max(x), 20)

    # Graficación de los datos y la regresión polinómica
    plt.scatter(x, y, label='Datos')
    plt.plot(x_reg, polinomio(x_reg), label='Regresión polinómica')
    plt.xlabel(name_x)
    plt.ylabel(name_y)
    plt.title('Regresión polinómica')
    plt.legend()
    plt.show()


if __name__=="__main__":

    # obtenemos los datos a evaluar -----------------------------
    df = pd.read_csv('datos.csv', sep=';')
    temperatura = df["temperatura"]
    glucosa = df["glucosa"]

    # 4.2 --------------------------------------------------------
        # regrecion lineal 
    r_lineal(temperatura, glucosa, "temperatura", "glucosa")
        # regrecion polinomica de grado 2
    r_poli_g_2(temperatura, glucosa, "temperatura", "glucosa")

    # 4.3 --------------------------------------------------------
        #polinomio de lagrange
    poli_lagrange(temperatura, glucosa, "temperatura", "glucosa")


