from math import sin,cos,factorial
"""

 vercion del lenguaje.python 3.9
"""
print(" ingrese el ultimo numero de su codigo estudiantil")
n_codigo=int(input(" -->:"))

if n_codigo<=2: 
    n=3

error_esperado= (0.5*(10**(2-n_codigo))) #

xi = 0.5
Xi_1 = 1
valor_ant=0
h=0
while True:
    st = (sin(xi**2)) + (2*xi*cos(xi**2))*h + (( 2*cos(xi**2) - 4*xi**2*sin(xi**2) ) / factorial(2))*(h**2) + (( -12*xi*sin(xi**2) - 8*(xi**3)*cos(xi**2) ) / factorial(3))*(h**3)

    error_relativo= abs(((st-valor_ant)/st)*100)

    if error_relativo<error_esperado:
        break


    valor_ant=st
    h+=Xi_1-xi

print("valor obtenido popr la serie de tylor:",st)
print("error relativo:", error_relativo," <  error esperado:",error_esperado)

