import math

# Datos proporcionados
P0 = 13000000  # Tamaño inicial de la población en enero de 1981
I = 383000     # Cantidad de personas adicionales debido a nacimientos en 1981

# Función que representa la ecuación P(t) - P0 * e^(kt) - (I/k) * (e^(kt) - 1)
def equation(k):
    return P0 * math.exp(k) + (I / k) * (math.exp(k) - 1)

# Derivada de la función
def derivative(k):
    return P0 * math.exp(k) + (I / k) * math.exp(k) - (I / k**2) * (math.exp(k) - 1)

# Valor de inicio para el método de Newton-Raphson
k_guess = 0.1  # Puedes elegir otro valor inicial si lo deseas

# Parámetros para controlar la convergencia del método
max_iterations = 100
tolerance = 1e-8

# Implementación del método de Newton-Raphson
k_new = k_guess
for i in range(max_iterations):
    k_old = k_new
    k_new = k_old - equation(k_old) / derivative(k_old)
    
    # Verificar si la diferencia entre las aproximaciones sucesivas es menor que la tolerancia
    if abs(k_new - k_old) < tolerance:
        break

# Resultado
tasa_crecimiento = k_new
print("Tasa de crecimiento por nacimiento:", tasa_crecimiento)
