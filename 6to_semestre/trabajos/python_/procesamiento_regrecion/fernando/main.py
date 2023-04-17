import numpy as np
import matplotlib.pyplot as plt  
from scipy.interpolate import lagrange # esta funcion nos ayuda aobtenr un polinomio de interpolacion de langrange

def regrecion_lineal(x,y):
    lx = x
    ly = y
    n = len(lx)
    
    sy=sxy=sx2=sx=0.0
    for i in range(n):
        sy = ly[i] + sy
        sx = lx[i] + sx
        sxy = lx[i]*ly[i] + sxy
        sx2 = lx[i]**2 + sx2

    xm = np.mean(lx)
    ym = np.mean(ly)
    a1 = (n*sxy-sx*sy)/(n*sx2-sx*sx)
    a0 = ym - a1*xm

    print(f"Media x={xm}\n media de y={round(ym,6)}\n suma xy={sxy}\n suma x2={sx2}\n suma x={sx}\n suma y={sy}")
    print(f"La regresion lineal es y={round(a0,6)}+{round(a1,6)}x")
    reg =lambda x: a0 + (a1*x)

    # puntos en x a evaluar en la grafica 
    x_reg = np.linspace(min(x), max(x), 100)

    # Graficación de los datos y la regresión lineal
    plt.scatter(x, y, label='Datos')
    plt.plot(x_reg, reg(x_reg), label='Regresión lineal')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Regresión lineal')
    plt.legend()
    plt.show()





def reg_pol_grado_2(x,y):
        #Regresion polinomial por Minimos cuadrados
    px = x
    py = y
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

    determinante_a0 =  sy*(sx2*sx4-sx3**2)-sx*(sxy*sx4-sx3*sx2y)+sx2*(sxy*sx3-sx2y*sx2)

    determinante_a1 = n*(sxy*sx4-sx3*sx2y)-sy*(sx*sx4-sx3*sx2)+sx2*(sx*sx2y-sxy*sx2)

    determinante_a2 = n*(sx2*sx2y-sxy*sx3)-sx*(sx*sx2y-sxy*sx2)+sy*(sx*sx3-sx2**2)

    a0 = determinante_a0/determinante
    a1 = determinante_a1/determinante
    a2 = determinante_a2/determinante

    print(f"La regresion polinomial grado 2 es y = {a0}+{a1}x+{a2}x**2")

    reg =lambda x: a0 + (a1*x) + (a2*(x**2))

    # puntos a evaluar en la grafica 
    x_reg = np.linspace(min(x), max(x), 100)

    # Graficación de los datos y la regrecion polinomica
    plt.scatter(x, y, label='Datos')
    plt.plot(x_reg, reg(x_reg), label='Regresión polinomial de grado 2')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Regresión polinomial')
    plt.legend()
    plt.show()


def polinomio_lagrange(x, y):

    # obtenemod el polinomio de lagrange a partir de los valores impares
    x_imp = [x[i] for i in range(len(x)) if i%2!=0]
    y_imp = [y[i] for i in range(len(y)) if i%2!=0]
    pol_lagrange = lagrange(x_imp, y_imp)

    
    # Graficamos el polinomio de Lagrange 
    plt.plot(x_imp, y_imp, 'o', label='datos')
    plt.plot(x_imp, pol_lagrange(x_imp), label='polinomio de Lagrange')
    plt.xlabel('horas de entrada')
    plt.ylabel('horas de salida')
    plt.title("polinomio de Lagrange ")
    plt.legend()
    plt.show()
    

if __name__=="__main__":
    #datos a utilizar 
    # variabe independiente x
    fuerza_agarre_urnal = [12.266, 13.533, 14.866, 16.3, 16.666, 17.7, 18.033, 19.533, 20.166, 21.132, 21.382, 21.566, 22.233, 22.633, 22.9333, 24.8, 26.666, 26.866, 31.733, 32.433]

        # variable dependiente y 
    fuerza_agarre_normal =[19.367, 17.033, 25.833, 27.5, 30.003, 26.467, 22.667, 30.133, 26.094, 27.467, 34.267, 46.167, 40.367, 31.533, 34.867, 36.2, 33.0, 34.267, 44.533, 42.067]

    # encontramso el modelo de regrecion lineal para los datos
    regrecion_lineal(fuerza_agarre_urnal, fuerza_agarre_normal)

    # encontramos la regrecion polinomial de segundo grado para los datos 
    reg_pol_grado_2(fuerza_agarre_urnal, fuerza_agarre_normal)

    # encontramos un polinomio de interpolaciond e langarnge para los datos
    polinomio_lagrange(fuerza_agarre_urnal, fuerza_agarre_normal)

