from math import *


go=1
while go==1:
    print(" aplicacion general del teorema de pitagoras")
    print(" probemoslo al encontarr una de las siguientes opciones")
    print(" 1) hipotenusa\n 2) cateto adyacente \n 3) cateto opuesto")

    op=int(input("\n ingrese su opcion deceada: "))
    while op<1 or op>3:
        print("\n opcion ingresada no valida")
        op=int(input("\n ingrese su opcion deceada nuevamente: "))

    if op==1:
        print("\n hallemos la hipotenusa")
        c1=float(input(" ingresa el valor del cateto adyacenet: "))
        c2=float(input(" ingresa el valor del cateto opuesto: "))
        hipotenusa=sqrt( c1**2 + c2**2)
        print(" la hipotenusa es igual a ",hipotenusa)

    elif op==2:
        print("\n hallemos la cateto adyacente")
        hipotenusa=float(input(" ingresa el valor de la hipotenusa: "))
        c2=float(input(" ingresa el valor del cateto opuesto: "))
        c1=sqrt( hipotenusa**2 - c2**2)
        print(" el cateto adyacente es igual a ",c1)

    else:
        print("\n hallemos la cateto opuesto")
        hipotenusa=float(input(" ingresa el valor de la hipotenusa: "))
        c1=float(input(" ingresa el valor del cateto adyacente: "))
        c2=sqrt( hipotenusa**2 - c1**2)
        print(" el cateto opuesto es igual a ",c2)

    go=int(input(" desea volver a probar el programa?\n 1 para si\n #!=1 para no\n --->"))

print("\n HASTA LA PROXIMAAA :) !!!!")