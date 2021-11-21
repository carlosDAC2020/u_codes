from math import *

print(" escuacion cuadratica")
print(" hallemos la solucion a una ecuacion de la forma aX^2+bX+c ")

a=float(input(" ingresa el valor de a: "))
b=float(input(" ingresa el valor de b: "))
c=float(input(" ingresa el valor de c: "))

determinate= (b**2) - (2*a*c)

if a==0:
    x=-c/b
    print(" \n la ecuacion es lineal \n y tiene como respuesta X=",x)

else:
    if determinate<0:
        print(" la ecuacion tiene raices imaginarias")
    else:
        x1=(-b + sqrt(determinate)) / (2*a)
        x2=(-b - sqrt(determinate)) / (2*a)
        print("\n solucion de la ecuacion")
        print(" x1=",x1,"\n x2=",x2)