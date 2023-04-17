import numpy as np
import matplotlib.pyplot as plt  
from scipy.interpolate import lagrange # esta funcion nos ayuda aobtenr un polinomio de interpolacion de langrange

# datos a utilizar 
edad = [14, 13, 43, 5, 37, 25, 11, 3, 3, 49, 40, 2, 41, 11, 12, 21, 2, 3, 12, 6, 13, 61, 13, 12, 8, 0, 19, 9, 1, 5, 10, 56, 0, 5, 1, 1, 2, 6, 10, 1]

duracion_sintomas = [5, 7, 6, 11, 10, 5, 10, 5, 7, 5, 7, 12, 6, 10, 6, 5, 4, 4, 4, 9, 8, 7, 8, 8, 8, 9, 5, 7, 12, 11, 9, 5, 8, 5, 5, 6, 7, 9, 5, 4]

# Definir función de regresión
def reg(x, a0, a1):
    return a0 + a1*x

# Datos
lx = np.array(edad)
ly = np.array(duracion_sintomas)
n = len(lx)

# Cálculo de las sumas
sy = np.sum(ly)
sx = np.sum(lx)
sxy = np.sum(lx*ly)
sx2 = np.sum(lx**2)

# Cálculo de los coeficientes de la regresión lineal
xm = np.mean(lx)
ym = np.mean(ly)
a1 = (n*sxy-sx*sy)/(n*sx2-sx*sx)
a0 = ym - a1*xm

# Cálculo del error estándar del estimado
y_pred = a0 + a1*lx
SE = np.sqrt(np.sum((ly - y_pred)**2)/(n - 2))

# Cálculo de la desviación estándar
SD = np.sqrt(np.sum((ly - ym)**2)/(n - 1))

# Cálculo del coeficiente de correlación
r = (n*sxy - sx*sy)/np.sqrt((n*sx2 - sx**2)*(n*np.sum(ly**2) - sy**2))

# Cálculo del coeficiente de determinación
R2 = r**2

# Impresión de resultados
print(f"La regresion lineal es \ny={round(a0,6)}+{round(a1,6)}x")
print(f"Error estándar del estimado: {round(SE, 6)}")
print(f"Desviación estándar: {round(SD, 6)}")
print(f"Coeficiente de correlación: {round(r, 6)}")
print(f"Coeficiente de determinación: {round(R2, 6)}")
#

# Puntos en x a evaluar en la grafica 
x_reg = np.linspace(min(edad), max(edad), 100)

# Graficación de los datos y la regresión lineal
plt.scatter(edad, duracion_sintomas, label='Datos')
plt.plot(x_reg, reg(x_reg, a0, a1), label='Regresión lineal')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Regresión lineal')
plt.legend()
plt.show()

#---------------------------------------------------------------------------------------

# Regresion polinomial de grado 2
px = edad
py = duracion_sintomas
n = len(px)
sx=sx2=sy=sx3=sxy=sx4=sx2y=0.0
for i in range(n):
    sx   = px[i] + sx
    sx2  = px[i]**2 + sx2
    sy   = py[i] + sy
    sx3  = px[i]**3 + sx3
    sxy  = px[i]*py[i] + sxy
    sx4  = px[i]**4 + sx4
    sx2y = (px[i]**2)*py[i] + sx2y

determinante = n*(sx2*sx4-sx3**2)-sx*(sx*sx4-sx3*sx2)+sx2*(sx*sx3-sx2**2)

a0 =  sy*(sx2*sx4-sx3**2)-sx*(sxy*sx4-sx3*sx2y)+sx2*(sxy*sx3-sx2y*sx2)

a1 = n*(sxy*sx4-sx3*sx2y)-sy*(sx*sx4-sx3*sx2)+sx2*(sx*sx2y-sxy*sx2)

a2 = n*(sx2*sx2y-sxy*sx3)-sx*(sx*sx2y-sxy*sx2)+sy*(sx*sx3-sx2**2)

a0 = a0/determinante
a1 = a1/determinante
a2 = a2/determinante

# Cálculo del error estándar del estimado
y_pred = a0 + a1*lx + a2*lx**2
SE = np.sqrt(np.sum((ly - y_pred)**2)/(n - 2))

# Cálculo de la desviación estándar
SD = np.sqrt(np.sum((ly - ym)**2)/(n - 1))

# Cálculo del coeficiente de correlación
r = (n*sxy - sx*sy)/np.sqrt((n*sx2 - sx**2)*(n*sx4 - sx2**2))

# Cálculo del coeficiente de determinación
R2 = r**2

# Impresión de resultados
print(f"\n La regresion polinomial grado 2 es \n y={round(a0,6)}+{round(a1,6)}x+{round(a2,6)}x**2")
print(f"Error estándar del estimado: {round(SE, 6)}")
print(f"Desviación estándar: {round(SD, 6)}")
print(f"Coeficiente de correlación: {round(r, 6)}")
print(f"Coeficiente de determinación: {round(R2, 6)}")


reg = lambda x: a0 + (a1*x) + (a2*(x**2))

# puntos a evaluar en la grafica 
x_reg = np.linspace(min(edad), max(edad), 100)
edad# Graficación de los datos y la regrecion polinomica
plt.scatter(edad, duracion_sintomas, label='Datos')
plt.plot(x_reg, reg(x_reg), label='Regresión polinomial de grado 2')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Regresión polinomial')
plt.legend()
plt.show()



# polinomia de lagrange 

# Tomar solo los primeros 20 elementos de cada lista
edad = edad[:20]
duracion_sintomas = duracion_sintomas[:20]

# Encontrar la regresión polinómica
polinomio = np.poly1d(np.polyfit(edad, duracion_sintomas, len(edad)-1))

# Puntos a evaluar en la grafica 
x_reg = np.linspace(10, 50, 25)

# Graficación de los datos y la regresión polinómica
plt.scatter(edad, duracion_sintomas, label='Datos')
plt.plot(x_reg, polinomio(x_reg), label='Regresión polinómica')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Regresión polinómica')
plt.legend()
plt.show()