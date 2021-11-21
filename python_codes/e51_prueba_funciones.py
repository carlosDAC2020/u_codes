from e50_funciones_random import *
"""-------------------------------------------------------------------
# prueba de funciones matematicas

numero=int(input(" ingresa un numero:"))

print(" que funcion decea probar?")
print("--->1 evaluar si un numero es par 0 impar")
print("--->2 evaluar si un numero es primo o no")
print("--->3 hayar el factorial de un numero")
print("--->4 hayar el valor absoluto de un numero")

option=int(input("\n escoja el numero de su opcion:"))
while option>4 or option<1:
    print("\n valor ingresado no valido")
    option=int(input(" escoja el numero de su opcion nuevamente:"))

if option==1:
    par_impar(numero)

elif option==2:
    n_primo(numero)

elif option==3:
    factorial(numero)

else:        
    valor_obsoluto(numero)
#------------------------------------------------------------------
"""

# prueba de funciones de listas y matrices

# creamos una lista aleatoria y la imprimimos
lis_ta=crate_lista()
for i in range(len(lis_ta)):
    print("",lis_ta[i],end="")

print("")
# creamos una mtriz aleatoria y la imprimimos
matr_iz=create_matriz()
for f in range(len(matr_iz)):
    for c in range(len(matr_iz)):
        print(" ",matr_iz[f][c],end="")
    print("")

pregunta=1
while pregunta==1:
    print("\n\n que funcion para la matriz decea probar?")
    print("--->1 imprimir diagonal principal")
    print("--->2 imprimir diagonal segundaria")
    print("--->3 suma de cada fila")
    print("--->4 suma de cada columna")
    print("--->5 mayor elemento de cada fila ")
    print("--->6 mayor elemento de cada columna")
    print("--->7 menores elemento de cada fila ")
    print("--->8 menores elemento de cada columna")
    print("--->9 promedio de cada fila ")
    print("--->10 promedio de cada columna")
    print("--->11 imprimir la triangular superor")
    print("--->12 imprimir la triangular inferior")

    option=int(input("\n escoja el numero de su opcion:"))
    while option>12 or option<1:
        print("\n valor ingresado no valido")
        option=int(input(" escoja el numero de su opcion nuevamente:"))

    if option==1:
        diagonal_1(matr_iz)

    elif option==2:
        diagonal_2(matr_iz)

    elif option==3:
        sum_filas(matr_iz)

    elif option==4:
        sum_columnas(matr_iz)

    elif option==5:
        may_elemento_filas(matr_iz)

    elif option==6:
        may_elemento_columnas(matr_iz)

    elif option==7:
        men_elemento_filas(matr_iz)

    elif option==8:
        men_elemento_columnas(matr_iz)

    elif option==9:
        promedio_filas(matr_iz)

    elif option==10:
        promedio_columnas(matr_iz)

    elif option==11:
        triangular_1(matr_iz)

    elif option==12:
        triangular_2(matr_iz)

    print("\n\n desea volver al menu \n-- 1 si\n--!=1 no")
    pregunta=int(input(" responda:"))