from random import choice

# ---------------------------  funciones auxiliares --------------------------------------------
def n_primo(num):# evaluar si un numero es primo o no
    if num==2:
        # si el parametro tomado es 2 se dice que el numero es primo 
        return True
    for i in range(2,num):
        if num%i==0:
            # cuando esto ocurre el numero no es primo     
            return False
    # seria el niumero primo
    return True


def n_Primo_aleatorio(): # obtenemos un numero primo aletoriamente en un rango del 1 al 100
    list_n_primos=[]
    # obtenemos los numeros primos situados en ciertpo rango de numeros 
    for i in range(1000):
        # validamos si aux es un numero primo 
        if n_primo(i)==True:
            list_n_primos.append(i) # agregamos el numero primo a una lista 

    # retornamos un numero aleatoria de la lista de numero primos 
    return choice(list_n_primos)
        

def factores_primos_n_primo(np): # obtenemos losm factores primos de un numero priimo
    factores_primos=[] # factores primos del parametro 
    for i in (2,np+1):
        while np%i==0:
            factores_primos.append(i)
            np=np/i
    return factores_primos    


def raiz_primitiva_n_primo(np): # obtenemos la raiz primitiva de un numero primo 

    list_factores_primos_n=factores_primos_n_primo(np-1) # factores primos del parametro menos 1

    for i in range(2,np-1):# obtenemos las raices primitivas 
        valido=0 # variable auxiliar para validar si i es una raiz primitiva del parametro np
        for pi in list_factores_primos_n:
            if i**((np-1) / pi) % np==1:
                valido+=1 # se le sumara 1 a la varianle valido en caso de que se cumpla la condicion
        if valido==0:
            return i # retornamos la primera raiz primitiva que encontremos 
#------------------------------------------------------------------------------------------   
    
#-------------------- publico -----------------------------------------
    # p= solicitar un numero  primo aleatorio 
p=n_Primo_aleatorio()
    # g=  solicitar una raiz primitiva del numero elegido p 
g=raiz_primitiva_n_primo(p)
#---------------------------------------------------------------------


#-------------------- claves privadas --------------------------------
    # solicitamos claves privadas ( cualquier numero )
        # a para esuario 1
print(" usuario 1")
name_1=input("nombre:")
a=int(input(" ingresar su clave privada :"))
        # b poara usuario 2
print("\n usuario 2")
name_2=input("nombre:")
b=int(input(" ingresar su clave privada :"))
#---------------------------------------------------------------------

#-------------------- claves publicas --------------------------------
    # generamos claves privadas para cada usuario 
        # A= (g**a) % p para el usuario 1
A=(g**a) % p
        # B= (g**b) % p para el usuario 2
B= (g**b) % p      
#---------------------------------------------------------------------

#-------------------- clave de secion  --------------------------------
    # cuando los usuarios 1 y 2 conocen las claves publicas del otro podemos 
    # obtener la clave de secion para cada uno de ls siguente forma 
        # K1=(B**a) % p para usuario 1
K1=(B**a) % p
        # K2=(A**b) % p para usuario 2
K2=(A**b) % p

print("         datos de la secion ")
print("     publicos ")
print(" p = ",p)
print(" g = ",g)

print("     usuarios ")
print(" usuario 1")
print(" nombre:",name_1)
print(" clave privada:",a)
print(" clave publica:",A)
print(" clave de secion:",K1)

print("\n usuario 2")
print(" nombre:",name_2)
print(" clave privada:",b)
print(" clave publica:",B)
print(" clave de secion:",K2)



