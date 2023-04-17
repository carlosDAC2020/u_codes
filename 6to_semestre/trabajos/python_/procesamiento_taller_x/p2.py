import os
import sympy
import math


def Limpiar_consola():
    if os.name == 'nt':  # Windows
        os.system('cls')
    else:  # Unix/Linux/MacOS
        os.system('clear')


def Pausar():
    input("Presione 'Enter' para continuar")


def imprimir_tabla(tabla):
    """
    Imprime en la consola una tabla dada como una lista de listas.
    La primera lista es la cabecera de la tabla.
    """
    print("\n")
    column_widths = [max(len(str(cell))+1 for cell in column)
                     for column in zip(*tabla)]
    row_format = "".join(["{:<" + str(width) + "}" for width in column_widths])

    for i, row in enumerate(tabla):
        if i == 0:
            print(row_format.format(*row))
            print("-" * sum(column_widths))
        else:
            print(row_format.format(*row))
    print("\n")


def Calcular_derivada(f: str) -> str:
    """
    Calcula la derivada de una función dada en forma de cadena de texto.

    Parámetros:
            f (str): Función a la que se le desea calcular la derivada.

    Retorna:
            str: Derivada de la función dada.
    """
    # Convertir la función en una expresión simbólica utilizando la librería sympy

    x = sympy.symbols('x')
    expr = sympy.sympify(f)

    # Calcular la derivada de la expresión simbólica
    expr_derivada = sympy.diff(expr, x)

    # Convertir la derivada en una cadena de texto
    derivada = str(expr_derivada)

    return derivada


def Biseccion(eq: str, a: float, b: float, tol: float = None, max: int = 100) -> list:
    """
    Encuentra la raíz de la función dada utilizando el método de bisección.

    Parámetros:
    eq (str): La ecuación a resolver.
    a (float): El límite inferior del intervalo inicial.
    b (float): El límite superior del intervalo inicial.
    tol (float): El criterio de parada (porcentaje de error relativo máximo aceptable).

    Retorna:
    (list) Tabla con las aproximaciones sucesivas a la raiz.
    """
    # Define la función f(x) que se quiere encontrar la raíz
    def f(x): return eval(eq)

    # Verificación de que la función cambie de signo en el intervalo dado
    if (f(a) * f(b)) > 0:
        print("Error: la función no cambia de signo en el intervalo dado.")
        return None

    # Creación de una lista para guardar la tabla con las aproximaciones sucesivas a la raíz
    tabla = [["n", "hi", "hr", "hf",
              "f(hi)", "f(hr)", "f(hf)", "Error relativo %"]]

    # Realización de las iteraciones para encontrar la raíz

    i = 0
    while True:
        i += 1
        c = (a + b) / 2  # Cálculo del punto medio
        if i == 1:
            c_ant = c
        # Agregación de los datos de la iteración a la tabla
        e_rel = abs((c-c_ant)/(c))
        tabla.append([i, a, c, b, f(a), f(c), f(b), e_rel*100])

        # Verificación de si se ha encontrado la raíz exacta
        if f(c) == 0 or (e_rel < tol and i > 1):
            break
        # Actualización del intervalo de búsqueda según el cambio de signo
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
        c_ant = c
    return tabla  # Retorno de la tabla con las aproximaciones sucesivas


def Falsa_posicion(eq: str, a: float, b: float, tol: float = None, num: int = 10) -> list:
    """
    Encuentra la raíz de la función dada utilizando el método de falsa posición.

    Parámetros:
    eq (str): La ecuación a resolver.
    a (float): El límite inferior del intervalo inicial.
    b (float): El límite superior del intervalo inicial.
    tol (float): El criterio de parada (porcentaje de error relativo máximo aceptable).

    Retorna:
    (list) Tabla con las aproximaciones sucesivas a la raiz.
    """
    # Define la función f(x) que se quiere encontrar la raíz
    def f(x): return eval(eq)

    # Inicializa las variables necesarias para el método
    c = 0
    contador = 0

    # Creación de una lista para guardar la tabla con las aproximaciones sucesivas a la raíz
    tabla = [["n", "hi", "hr", "hf",
              "f(hi)", "f(hr)", "f(hf)", "Error relativo %"]]
    # Itera hasta que se alcance el criterio de parada
    i = 0
    while True:
        i += 1
        # Calcula la aproximación de la raíz utilizando la fórmula del método
        c = b - (f(b) * (a - b)) / (f(a) - f(b))
        if i == 1:
            c_ant = c
        e_rel = abs((c - c_ant) / c)

        # Agrega las aproximaciones y errores relativos a la lista de iteraciones
        tabla.append([i, a, c, b, f(a), f(c), f(b), e_rel*100])

        # Actualiza los valores de los límites del intervalo según el teorema de Bolzano
        if f(a) * f(c) < 0:
            b = c
        else:
            a = c

        # Verifica si se alcanzó el criterio de parada
        if tol is not None:
            if e_rel < tol and i > 1:
                break
        else:
            if contador == num:
                break

        c_ant = c
        contador += 1

    return tabla  # Retorno de la tabla con las aproximaciones sucesivas


def Punto_fijo(eq: str, x0: float, tol: float = 1e-6, max_iter: int = 100) -> list:
    """
    Calcula la raíz de la función dada, por el método de iteración de punto fijo.

    Parámetros:
    eq (str): Función de la cual se busca la raíz.
    x0 (float): Valor inicial para la iteración.
    tol (float): Tolerancia para el criterio de parada (por defecto 1e-6).
    max_iter (int): Número máximo de iteraciones permitidas (por defecto 100).

    Retorna:
    (list) Tabla con las aproximaciones sucesivas a la raiz.
    """
    # Define la función f(x) que se quiere encontrar la raíz
    def f(x): return eval(eq)

    # Inicializamos las variables necesarias para el método
    fx = f(x0)
    iteraciones = 0
    error = tol + 1

    # Creación de una lista para guardar la tabla con las aproximaciones sucesivas a la raíz
    tabla = [["n", "x", "f(x)", "Error relativo %"]]
    tabla.append([0, x0, f(x0), 0])

    # Comenzamos el ciclo iterativo
    while fx != 0 and error > tol and iteraciones < max_iter:
        # Calculamos la nueva aproximación
        x1 = f(x0)
        fx = f(x1)
        # Calculamos el error relativo
        error = abs((x1 - x0) / x1)
        # Actualizamos los valores de x0 y las iteraciones
        x0 = x1
        iteraciones += 1

        # Agregamos los resultados de esta iteración a la tabla
        tabla.append([iteraciones, x0, fx, error*100])

    # Comprobamos si se alcanzó la convergencia
    if fx == 0:
        print("Se ha encontrado la raíz exacta.")
    elif error <= tol:
        print("Se ha alcanzado la convergencia.")
    else:
        print("El método no converge.")
        return None

    return tabla  # Retorno de la tabla con las aproximaciones sucesivas


def Newton_raphson(eq: str, x0: float, tol: float = 1e-6) -> list:
    """
    Calcula la raíz de la función dada, por el método de iteración de newton raphson.

    Parámetros:
    eq (str): Función de la cual se busca la raíz.
    x0 (float): Valor inicial para la iteración.
    tol (float): Tolerancia para el criterio de parada (por defecto 1e-6).

    Retorna:
    (list) Tabla con las aproximaciones sucesivas a la raiz.
    """
    # Define la función f(x) que se quiere encontrar la raíz
    def fx(x): return eval(eq)
    def dfx(x): return eval(Calcular_derivada(eq))

    # Creación de una lista para guardar la tabla con las aproximaciones sucesivas a la raíz
    tabla = [["n", "xi", "Error relativo %"]]
    tabla.append([0, x0, 0])
    # Inicialización de variables
    x = x0
    i = 0

    # Loop principal del método de Newton-Raphson
    while True:
        i += 1  # Incrementar contador de iteraciones
        x_prev = x  # Guardar el valor anterior de x
        x = x - fx(x)/dfx(x)  # Calcular el nuevo valor de x

        # Calcular el error relativo y agregar una nueva fila a la tabla
        e_rel = abs((x - x_prev) / x)
        tabla.append((i, x, e_rel*100))

        if e_rel < tol and i > 1:  # Verificar la condición de parada
            break

    return tabla  # Retorno de la tabla con las aproximaciones sucesivas


def Menu():
    while True:
        # Imprimir el menú
        print("----- Menú Principal -----")
        print("1. Bisección")
        print("2. Falsa posición")
        print("3. Iteración de punto fijo")
        print("4. Newton Raphson")
        print("5. Salir")

        # Solicitar la entrada del usuario
        opcion = input("\nIngrese el número de la opción que desea ejecutar: ")

        # Realizar una acción basada en la opción seleccionada
        if opcion == "1":
            Limpiar_consola()
            print("----> Bisección\n")
            # Datos de entrada necesarios para el método de bisección
            eq = input("Ingrese la ecuación a resolver: ")
            a = float(input("Ingrese el límite inferior del intervalo: "))
            b = float(input("Ingrese el límite superior del intervalo: "))
            tol = float(
                input("Ingrese el porcentaje de error relativo máximo aceptable: "))

            # Llamado de la función Bisección para encontrar la raíz
            tabla = Biseccion(eq, a, b, tol)

            # Impresión de la tabla con las aproximaciones sucesivas a la raiz
            if tabla is not None:
                imprimir_tabla(tabla)

        elif opcion == "2":
            Limpiar_consola()
            print("----> Falsa posición\n")
            # Datos de entrada necesarios para el método de falsa posición
            eq = input("Ingrese la ecuación a resolver: ")
            a = float(input("Ingrese el límite inferior del intervalo: "))
            b = float(input("Ingrese el límite superior del intervalo: "))
            tol = float(
                input("Ingrese el porcentaje de error relativo máximo aceptable: "))

            # Llamado de la función Falsa posición para encontrar la raíz
            tabla = Falsa_posicion(eq, a, b, tol)

            # Impresión de la tabla con las aproximaciones sucesivas a la raiz
            if tabla is not None:
                imprimir_tabla(tabla)

        elif opcion == "3":
            Limpiar_consola()
            print("----> Iteración de punto fijo\n")
            # Datos de entrada necesarios para el método de iteración de punto fijo
            eq = input("Ingrese la ecuación a resolver: ")
            a = float(input("Ingrese el valor inicial para la iteración: "))
            tol = float(
                input("Ingrese el porcentaje de error relativo máximo aceptable: "))

            # Llamado de la función Punto fijo para encontrar la raíz
            tabla = Punto_fijo(eq, a, tol)

            # Impresión de la tabla con las aproximaciones sucesivas a la raiz
            if tabla is not None:
                imprimir_tabla(tabla)

        elif opcion == "4":
            Limpiar_consola()
            print("----> Newton Raphson\n")
            # Datos de entrada necesarios para el método de newton raphson
            eq = input("Ingrese la ecuación a resolver: ")
            a = float(input("Ingrese el valor inicial para la iteración: "))
            tol = float(
                input("Ingrese el porcentaje de error relativo máximo aceptable: "))

            # Llamado de la función newton raphson para encontrar la raíz
            tabla = Newton_raphson(eq, a, tol)

            # Impresión de la tabla con las aproximaciones sucesivas a la raiz
            if tabla is not None:
                imprimir_tabla(tabla)

        elif opcion == "5":
            print("Saliendo del programa...")
            break
        else:
            print("Opción inválida. Por favor ingrese un número del 1 al 5.")
        Pausar()
        Limpiar_consola()


Menu()
