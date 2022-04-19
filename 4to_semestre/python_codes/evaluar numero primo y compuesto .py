"""
def n_primo_o_compuesto(num):# evaluar si un numero es primo o compuesto
    if num==2:
        return "primo"
        
    for i in range(2,num):
        if num%i==0:
            return "compuesto"     

    return "primo"
    
# ingreso de un numero pro parte del usuario 
num=int(input(" ingrese un numero:"))
print(" el numero ingresado es un numero ",n_primo_o_compuesto(num))

"""
#------------------------------------------------------------------------
"""
print(" ingreso de rango de valores ")
num1=int(input(" valor 1:"))
num2=int(input(" valor 2:"))
while num1>num2:
    print(" el valor 2 debe ser mayor que el valor 1")
    num2=int(input(" ingrese el valor 2 nuevamente:"))

print("\n numero pares entre ",num1," y ", num2)

while num1<=num2:
    if num1%2==0:
        4
        print(num1)
    num1+=1
"""
#---------------------------------------------------------------------------------
"""
minusculas=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']  
mayusculas=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']  
todas=minusculas+mayusculas  
vocales=['a','e','i','o','u'] 


def vocalConsonante(letrita):  
  if letrita in vocales:    
   return 1 # cuando es una volcal 
  else:    
   return 2 # cuando es una consonante 
 
# variables auxiliares para hacer las cuentas de cada caracter
cant_vocales=0
cant_consonantes=0
cant_nums=0

go=1
while go==1:
    print("puede ingresar 99 para detener la ejecucion")
    caracter=input("ingresa algun caracter numerico o alfa numerico:")
    # en caso de detener la ejecucion 
    if caracter=="99":
        break
    99
        # cuando el caracter ingresado es una letra
    if caracter in todas:
        x=vocalConsonante(caracter)
        if x==1:
            cant_vocales+=1
        else:
            cant_consonantes+=1

        # cuando el caracter es un numero 
    else:
        cant_nums+=1

    

print(" CANTIDADES ")
print("cantidad de vocales:",cant_vocales)
print("cantidad de consonantes:",cant_consonantes)
print("cantidad de numeros :",cant_nums)

"""
#------------------------------------------------------
"""
from random import randint

vectorA=[]
for i in range(50):# asiganamos valores aleatorios a los elementos de la lista 
    element=randint(1,100) 
    vectorA.append(element)

vectorB=[]# vector para numeros pares 
vectorC=[]# vector para los numeros umpares
for i in vectorA: # asiganamos sus elemetso a alos vectores correspondientes 
    if i%2==0:
        vectorB.append(i)
    else:
        vectorC.append(i)

if len(vectorB) > len(vectorC):
    for i in range( len(vectorC) , len(vectorB) ):
        vectorC.append(0)
else:
    for i in range( len(vectorB) , len(vectorC) ):
        vectorB.append(0)

print(" vector inicial")
print(vectorA)
print(" vector numeros pares ")
print(vectorB)
print(" vector numeros impares ")
print(vectorC)
"""
#--------------------------------------------------------------------
"""
from random import randint

vector1=[]
vector2=[]
tan=int(input("ingresa el tamaño del los vectores iniciales:"))

for i in range(tan): 
        # asignacion del vector 1
    element=randint(1,100) 
    vector1.append(element)
        # asignacion del vector 2
    element=randint(1,100) 
    vector2.append(element)

# ordenamos de menor a mayor los vectores 1 y 2     
vector1.sort()
vector2.sort()

vector3=[] # creamos y asignamos valores al vector 3 el cual es una funcion del vector 1 y 2
for i in vector1:
    vector3.append(i)
        
for i in vector2:        
    vector3.append(i)

vector3.sort() # ordenamos el vector 3 de menor a mayor elemento

print(" vector 1")
print(vector1)
print(" vector 2 ")
print(vector2)
print(" vector 3 funcionn de 1 y 2 ")
print(vector3)
"""
#---------------------------------------------------------------------
"""
from random import randint
list=[]# lista que guardala los cuadrados de los numeros enteros del 1 al 100
for i in range(1,101):
    list.append(i*i)

print(" lista de los cuadrados de los primeros cien numeros enteros ")
print(list)
"""
#---------------------------------------------------------------------
"""
from random import randint
list=[]

tan=int(input("ingresa el tamaño de la lista:"))
    # variables auxiliares para realizar las sumatorias correspondientes 
sum_num_impares=0
sum_num_pares=0
    # asiganamos elementos aleatorios a la lita a la par que vamos haciendo las sumatorias correspondientes 
for i in range(tan):
    elemento=randint(1,100)
    list.append(elemento)

    if(elemento%2==0): # para numeros pares 
        sum_num_pares+=elemento
    else:    # para numeros impares 
        sum_num_impares+=elemento

print( "lista de ekementos")
print(list)
print("suma de numeros pares:",sum_num_pares)
print(" suma de numeros impares:",sum_num_impares)
"""
#-----------------------------------------------------------------------
"""
from random import randint

def asignacion_ventas(almacen):
    for i in range(6):
        # asignacion de ventas al almacen 
        ventas=randint(50,500)
        almacen.append(ventas)

def imprimir_info_ventas(almacen):
    print("\n\nventas del ",almacen[0])
    print("-"*68)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}| ".format("mes 1","mes 2","mes 3","mes 4","mes 5","mes 6"))
    print("-"*68)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}| ".format(almacen[1],almacen[2],almacen[3],almacen[4],almacen[5],almacen[6]))
    print("-"*68)
    print(" el promedio de ventas por mes de este almacen fue de :",round(prom_ventas_X_almacen(almacen),2))

def prom_ventas_X_almacen(almacen):
    sum_ventas=0
    for i in range(1,6):
        sum_ventas+=almacen[i]
    return sum_ventas/6

def prom_global(almacenes):
    sum_global=0
    for i in almacenes:
        sum_global+=prom_ventas_X_almacen(i)

    return sum_global/5

def almacenes_con_may_prom(almacenes): # funcion que retorna una lista con los almacenes que superaron el promedio de ventas globlal
    prom_Global=prom_global(almacenes)
        # lista que almacenara a los almacenes que superen el promedio global 
    list_alms=[]
    for i in almacenes:
        if prom_ventas_X_almacen(i)>prom_Global:
            list_alms.append(i[0])

    return list_alms


    # declaramos las listas que tendran los datos de ventas de los empleados 
ventas_alm_1=["almacen 1"]
asignacion_ventas(ventas_alm_1)
imprimir_info_ventas(ventas_alm_1)

ventas_alm_2=["almacen 2"]
asignacion_ventas(ventas_alm_2)
imprimir_info_ventas(ventas_alm_2)

ventas_alm_3=["almacen 3"]
asignacion_ventas(ventas_alm_3)
imprimir_info_ventas(ventas_alm_3)

ventas_alm_4=["almacen 4"]
asignacion_ventas(ventas_alm_4)
imprimir_info_ventas(ventas_alm_4)

ventas_alm_5=["almacen 5"]
asignacion_ventas(ventas_alm_5)
imprimir_info_ventas(ventas_alm_5)

# lista que contiene a todos los almacenes 
almacenes=[ventas_alm_1,ventas_alm_2,ventas_alm_3,ventas_alm_4,ventas_alm_5]
print("\n promedio global de ventas entre todos los almacenes fue de:",round(prom_global(almacenes),2))

# almacenes que superaron el promedio global de ventas 
list_best_almacenes=almacenes_con_may_prom(almacenes)

if(len(list_best_almacenes)>0):
    print("\n almacenes que superaron el promedio global de ventas a nivel individual ")
    for alms in list_best_almacenes:
        print(alms)
else:
    print("\n nungun almacen supero el promedio global de ventas")
"""
#----------------------------------------------------------------------



def validaCodigo(codigo):
    # listas auxiliares para hacer la validacion 
    minusculas=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']  
    mayusculas=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']  
    todas=minusculas+mayusculas 
    avisos=[] # lista de avisos de verificacion del usuario
    if (len(codigo)<9 or len(codigo)>9): # validamos la cantidad de caracteres
        avisos.append(" el codigo debe tener 9 caracteres")

    else:
        val=codigo[0]+codigo[1]
        if (val!="ce"):# validamos que los dos priemros caracteres del codigo sean CE
            avisos.append(" los dos primeros caracteres deber ser ce o CE")

        if (codigo[8]!="z"): # verificamos que el ultimo caracter sea z
            avisos.append(" el ultimo caracter debe ser Z")

        for i in range(2,7): # validamos que los caracteres de 3 al 8 sean numeros 
            if codigo[i] in todas:
                avisos.append("del caracter 3 al 8 denben ser numeros")
                break

    if (len(avisos)>0):
        print(" avisos de validacion")
        for i in avisos:
            print(i)
        return 0
    else:
        print(" codigo valido")
        return 1 # se retorna 1 en caso de que el codigo este bien 
    
def imrpimeCategorias(categoria):
    if (len(categoria)>0):
        print("codigos")
        for i in categoria:
            print(i)
    else:
        print("--")
    
# listas con la informacion de los estudiantes 
codigos=[]
notas=[]
num_e=int(input(" ingrese la cantidad de estudiantes a evaluar:"))

# nota mayor y menor 
not_may=0
not_men=6

# nota promedio del curso
sum_notas=0

# estudiantes aprovados y reprobados 
est_aprovados=0
est_reprovados=0

# grupos de notas
excelente=[] # notas de 5.0
sobresaliente=[] # notas entre 4.0 y menos de 5.0
suficiente=[] # notas entre 3.0 y menos de 4.0
reprovado=[] # notas de menos de 3.0

print(" ingreso de datos de estudiantes")
for i in range(num_e):
    print("\n estudiante ",i)
    val=0
    while val==0:
        codigo=input(" ingrese un codigo (ingresar letras en minusculas!!!):")
        val=validaCodigo(codigo)
        if (val==1):
            codigos.append(codigo)

    nota=float(input("ingrese su nota:"))
    while(nota<1 or nota>5):
        print(" nota ingresada no valida!!")
        nota=float(input("ingrese su nota nuevamente:"))
    notas.append(nota)

    # sumatoria de notas para obtener el promedio
    sum_notas+=nota


    if( nota==5.0):
        excelente.append(codigo)

    elif(nota>=4 and nota<5):
        sobresaliente.append(codigo)
    
    elif(nota>=3 and nota<4):
        suficiente.append(codigo)

    else:
        reprovado.append(codigo)

    print("-"*35)

print("\n DATOS GENERALES DEL GRUPO")
print(" promedio del grupo:",round(sum_notas/num_e,2))

    # estudiantes arpovados 
est_aprovados=len(excelente) + len(sobresaliente) + len(suficiente) 
print(" numero de estudiantes aprovados:",est_aprovados)
    # estudiantes reprovados
est_reprovados=len(reprovado)
print(" numero de estudiantes reprovados:",est_reprovados)

print("\n niveles de desempeño")
print("\nexcelente ",len(excelente),"estudientes")
imrpimeCategorias(excelente)

print("\nsobresaliente ",len(sobresaliente),"estudientes")
imrpimeCategorias(sobresaliente)

print("\nsuficiente ",len(suficiente),"estudientes")
imrpimeCategorias(suficiente)

print("\ninsuficiente ",len(reprovado),"estudientes")
imrpimeCategorias(reprovado)

print("\n porcentajes")
porcent_aprovados=round((est_aprovados/num_e)*100,2)
print(" estudientes aprovados:",porcent_aprovados)

porcent_reprovados=round((est_reprovados/num_e)*100,2)
print(" estudientes reprovados:",porcent_reprovados)