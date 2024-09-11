import numpy as np
import matplotlib.pyplot as plt


# Definición de la función W(t)
W = lambda t: 100 * np.sin(np.pi * t / 8)




def trapecio(a, b, n, f):
    """
    Calcula la integral definida de una función utilizando el método del trapecio.

    Parámetros:
    a (float): Límite inferior de la integración.
    b (float): Límite superior de la integración.
    n (int): Número de subdivisiones (trapezoides).
    f (function): Función a integrar.
    """
    h = (b - a) / n
    integral = 0.5 * (f(a) + f(b))
    for i in range(1, n):
        integral += f(a + i * h)
    integral *= h
    return integral


def simpson_1_3(a, b, n, f):
    """
    Calcula la integral definida de una función utilizando el método de Simpson 1/3.

    Parámetros:
    a (float): Límite inferior de la integración.
    b (float): Límite superior de la integración.
    n (int): Número de subdivisiones (debe ser par).
    f (function): Función a integrar.
    """
    if n % 2 == 1:  
        n += 1
    h = (b - a) / n
    integral = f(a) + f(b)
    for i in range(1, n, 2):
        integral += 4 * f(a + i * h)
    for i in range(2, n-1, 2):
        integral += 2 * f(a + i * h)
    integral *= h / 3
    return integral


def simpson_3_8(a, b, n, f):
    """
    Calcula la integral definida de una función utilizando el método de Simpson 3/8.

    Parámetros:
    a (float): Límite inferior de la integración.
    b (float): Límite superior de la integración.
    n (int): Número de subdivisiones (debe ser múltiplo de 3).
    f (function): Función a integrar.
    """
    if n % 3 != 0:  
        n += 3 - (n % 3)
    h = (b - a) / n
    integral = f(a) + f(b)
    for i in range(1, n):
        if i % 3 == 0:
            integral += 2 * f(a + i * h)
        else:
            integral += 3 * f(a + i * h)
    integral *= 3 * h / 8
    return integral


trapeci_o=trapecio(0,40,39,W)
simpson13=simpson_1_3(0,40,36,W)
simpson38=simpson_3_8(0,40,36,W)
xv = 509.29582 
print(xv)
print("-"*76)
print("|{:^15}|{:^15}|{:^10}|{:^15}|{:^15}|".format("metodo","Intervalos","Resultado","ER relativo","ER %"))
print("-"*76)
print("|{:^15}|{:^15}|{:^10}|{:^15}|{:^15}|".format("Trapecio",39,round(trapeci_o,4),abs(round(xv-trapeci_o,4)),abs(round(((xv-trapeci_o)/trapeci_o),4))))
print("|{:^15}|{:^15}|{:^10}|{:^15}|{:^15}|".format("Simpson 1/3",36,round(simpson13,4),abs(round(xv-simpson13,4)),abs(round(((xv-simpson13)/simpson13),4))))
print("|{:^15}|{:^15}|{:^10}|{:^15}|{:^15}|".format("Simpson 3/8",36,round(simpson38,4),abs(round(xv-simpson38,4)),abs(round(((xv-simpson38)/simpson38),4))))
print("-"*76)

"""# Generar valores de t desde 0 hasta 8 con un incremento pequeño para una curva suave
t_values = np.linspace(0, 40, 100)
W_values = W(t_values)

# Crear la gráfica
plt.figure(figsize=(10, 6))
plt.plot(t_values, W_values, label=r'$W(t) = 100 \sin\left(\dfrac{\pi t}{8}\right)$', color='b')

# Agregar etiquetas y título
plt.title('Carga de Trabajo en una Línea de Producción')
plt.xlabel('Tiempo (horas)')
plt.ylabel('Carga de Trabajo (unidades de trabajo/hora)')
plt.legend()
plt.grid(True)

# Mostrar la gráfica
plt.show()




trapecio

# Calcular puntos para graficar la función
    x = np.linspace(a, b, 100)
    y = f(x)

    # Calcular puntos para los trapecios
    x_trap = np.linspace(a, b, n+1)
    y_trap = f(x_trap)

    # Crear gráfico
    plt.figure(figsize=(8, 6))
    plt.plot(x, y, 'b', label='f(x)')
    for i in range(n):
        plt.fill_between([x_trap[i], x_trap[i+1]], [y_trap[i], y_trap[i+1]], alpha=0.3)
    plt.title('Área bajo la curva utilizando el método del trapecio')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid(True)
    plt.show()



simpson 13
# Calcular puntos para graficar la función
    x = np.linspace(a, b, 100)
    y = f(x)

    # Calcular puntos para la regla de Simpson 1/3
    x_simpson = np.linspace(a, b, n+1)
    y_simpson = f(x_simpson)

    # Crear gráfico
    plt.figure(figsize=(8, 6))
    plt.plot(x, y, 'b', label='f(x) = x^2')
    for i in range(0, n, 2):
        plt.fill_between([x_simpson[i], x_simpson[i+2]], [y_simpson[i], y_simpson[i+2]], alpha=0.3)
    plt.title('Área bajo la curva utilizando la regla de Simpson 1/3')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid(True)
    plt.show()




simpson 38



"""



