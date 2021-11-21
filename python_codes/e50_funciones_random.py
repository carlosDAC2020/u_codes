# funciones random resiclables
import random # libreria necesaria para ciertas funciones

#----- matematicas basicas-------------------------------------

def par_impar(num): # evaluar si un numero es par o impar 
    if num%2==0:
        #print("par")
        return True
    else:
        #print("impar")
        return False

def n_primo(num):# evaluar si un numero es primo o no
    if num==2:
        print("primo")
        return True
    for i in range(2,num):
        if num%i==0:
            print(" no es primo")     
            return False
    print("primo")
    return True

def factorial(num): # hayar el factorial de un numero
    fact=1
    while num>1:
        fact*=num
        num-=1
    print("factorial=",fact)
    return fact

def valor_obsoluto(num): # hayar el valor obsoluto de un numero
    if num<1:
        num*=-1
        print("valor absoluto=",num)
        return num
    print("valor absoluto=",num)
    return num

#----------------------------------------------------------------

#------listas y matrices-----------------------------------------

def crate_lista():# crar una lista con numeros aleatorios
    lista=[]
    cant=int(input(" cantidad de elementos de la lista:"))
    
    # ingresamos elementos a la lista a travev de un bucle for
    for i in range(cant):
        # señalamos un rango de valores a escojer para ingresar elementos a la lista
        element=random.randint(1,50) # este rango de numeros puede variar
        lista.append(element)
    
    return lista 

def create_matriz(): # crear unamatriz con numeros aleatorios
    # señalamos filas y columnas
    filas=int(input(" numero de filas:"))
    columnas=int(input(" numero de columnas:"))

    # creamos la matriz
    matriz=[[0 for c in range(columnas)]for f in range(filas)]

    # agregamos elementos a la matriz usando un doble bucle for anidado
    for f in range(filas):
        for c in range(columnas):
            # señalamos un rango de valores para agregar a la lista
            matriz[f][c]=random.randint(1,50)
    
    return matriz

def diagonal_1(matriz): # imprimir la diagonal principal de una matriz
    
    # se asume q la matriz es cuadrada y guardamos el valor de su longitud es la siguente variable auxiliar 
    cd=len(matriz)  # esto es igual al numero de filas y cokumnas
    
    # procedemos a imprimir los elementos de la diagonal en cuestion
    for f in range(cd):
        for c in range(cd):
            if f==c:
                print(" ",matriz[f][c],end=" ")
            else:
                print(" ",0,end=" ")
        print("")

def diagonal_2(matriz): # imprimir la diagonal segundaria de una matriz
   
    # se asume q la matriz es cuadrada y guardamos el valor de su longitud es la siguente variable auxiliar 
    cd=len(matriz) # esto es igual al numero de filas y cokumnas
   
    # procedemos a imprimir los elementos de la diagonal en cuestion
    for f in range(cd):
        for c in range(cd):
            if f+c == cd-1:
                print(" ",matriz[f][c],end=" ")
            else:
                print(" ",0,end=" ")
        print("")

def sum_filas(matriz): # suma de cada fila
    # asumiendo que la matriz es cuadrada
    aux=len(matriz)
    # lista donde se almacenaran los resultad0s de la sumas de cada fila
    list_sum_f=[]
    # realizamos el proceco de la suma con un bucle anidado
    for f in range(aux):
        sum_f=0
        for c in range(aux):
            sum_f+=matriz[f][c]
        list_sum_f.append(sum_f)
    # imprimimos resuktados
    print(" sumas de cada fila")
    for i in range(len(list_sum_f)):
        print(" fila",i,"=",list_sum_f[i])

def sum_columnas(matriz): # suma de cada columna
    # asumiendo que la matriz es cuadrada
    aux=len(matriz)
    # lista donde se almacenaran los resultad0s de la sumas de cada columna
    list_sum_c=[]
    # realizamos el proceco de la suma con un bucle anidado
    for c in range(aux):
        sum_c=0
        for f in range(aux):
            sum_c+=matriz[f][c]
        list_sum_c.append(sum_c)
    # imprimimos resuktados
    print(" sumas de cada columna")
    for i in range(len(list_sum_c)):
        print(" columna",i,"=",list_sum_c[i])

def may_elemento_filas(matriz): # obtenerel mayor elemento de cada fila de una matriz
    # asumimos que la matriz es cuadrada
    aux=len(matriz)
    # declaramos una lista donde se almacenen los elementos amyores de cada fila
    may_elmts_f=[]
    # utilizamos un bucle for para evaluar los elementos de la matiz
    for f in range(aux):
        el_may_f=matriz[f][0]
        for c in range(aux):
            if el_may_f < matriz[f][c]:
                el_may_f=matriz[f][c]
        may_elmts_f.append(el_may_f)
    # imprimimos los resultados
    print(" mayores elementos de cada fila")
    for i in range(len(may_elmts_f)):
        print(" fila",i,may_elmts_f[i])

def may_elemento_columnas(matriz): # obtenerel mayor elemento de cada columnas de una matriz
    # asumimos que la matriz es cuadrada
    aux=len(matriz)
    # declaramos una lista donde se almacenen los elementos amyores de cada columna
    may_elmts_c=[]
    # utilizamos un bucle for para evaluar los elementos de la matiz
    for c in range(aux):
        el_may_c=matriz[0][c]
        for f in range(aux):
            if el_may_c < matriz[f][c]:
                el_may_c=matriz[f][c]
        may_elmts_c.append(el_may_c)
    # imprimimos los resultados
    print(" mayores elementos de cada columna")
    for i in range(len(may_elmts_c)):
        print(" fila",i,may_elmts_c[i])

def men_elemento_filas(matriz): # hayar los elementos menores de cada fila en una matriz
    # asumimos que la matriz es cuadrada
    aux=len(matriz)
    # declaramos una lista donde se almacenen los elementos menores de cada fila
    men_elmts_f=[]
    # utilizamos un bucle for para evaluar los elementos de la matiz
    for f in range(aux):
        el_men_f=matriz[f][0]
        for c in range(aux):
            if el_men_f > matriz[f][c]:
                el_men_f=matriz[f][c]
        men_elmts_f.append(el_men_f)
    # imprimimos los resultados
    print(" menores elementos de cada fila")
    for i in range(len(men_elmts_f)):
        print(" fila",i,men_elmts_f[i])

def men_elemento_columnas(matriz): # hayar los elementos menores de cada columna de una matriz
    # asumimos que la matriz es cuadrada
    aux=len(matriz)
    # declaramos una lista donde se almacenen los elementos menores de cada columna
    men_elmts_c=[]
    # utilizamos un bucle for para evaluar los elementos de la matiz
    for c in range(aux):
        el_men_c=matriz[0][c]
        for f in range(aux):
            if el_men_c > matriz[f][c]:
                el_men_c=matriz[f][c]
        men_elmts_c.append(el_men_c)
    # imprimimos los resultados
    print(" menores elementos de cada columna")
    for i in range(len(men_elmts_c)):
        print(" fila",i,men_elmts_c[i])

def promedio_filas(matriz): # hayar el promedio de cada fila
    # asumiendo que la matriz es cuadrada
    aux=len(matriz)
    # lista donde se almacenene los promedios de cada fila
    lst_prom_f=[]
    # usamoa un bucle for para realizar el proceso de promediado 
    for f in range(aux):
        sum_f=0
        for c in range(aux):
            sum_f+=matriz[f][c]
        prom_f= sum_f / aux
        lst_prom_f.append(prom_f)
    # imprimimos los resultados
    print(" promedios de cada fila")
    for i in range(len(lst_prom_f)):
        print(" fila",i,lst_prom_f[i])

def promedio_columnas(matriz): # hayar el promedio de cada fila
    # asumiendo que la matriz es cuadrada
    aux=len(matriz)
    # lista donde se almacenene los promedios de cada columna
    lst_prom_c=[]
    # usamoa un bucle for para realizar el proceso de promediado 
    for c in range(aux):
        sum_c=0
        for f in range(aux):
            sum_c+=matriz[f][c]
        prom_c= sum_c / aux
        lst_prom_c.append(prom_c)
    # imprimimos los resultados
    print(" promedios de cada columna")
    for i in range(len(lst_prom_c)):
        print(" fila",i,lst_prom_c[i])

def triangular_1(matriz): # imprimir la triangular superior de la matriz
    # asumimos que la matriz es cuadrada
    aux=len(matriz)
    # con un doble bucle anidado imprimimos la triangular superior
    print(" triangular superior")
    for f in range(aux):
        for c in range(aux):
            if f<c:
                print(" ",matriz[f][c],end=" ")
            else:
                print(" ",0,end=" ")
        print("")

def triangular_2(matriz): # imprimir la triangular inferior de la matriz
    # asumimos que la matriz es cuadrada
    aux=len(matriz)
    # con un doble bucle anidado imprimimos la triangular inferior
    print(" triangular inferior")
    for f in range(aux):
        for c in range(aux):
            if f>c:
                print(" ",matriz[f][c],end=" ")
            else:
                print(" ",0,end=" ")
        print("")