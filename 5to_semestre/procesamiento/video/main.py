import numpy as np


# funcion a evaluar 
f = lambda x: np.log(x) + x - 5
# derivada de la funcion 
df = lambda x: (1/x)+1 

# metodos de evalucion 
fixed_point = lambda x: -np.log(x) + 5 # punto fijo
Newton_Raphson = lambda x: x - ((f(x))/(df(x))) # Newton-Raphson

def evaluacion(metodo, Xi, es):
    # se guarda el valor anterior de xi+1 para 
    # obtener el valor del error relativo
    Xi1_ant=0

    print("-"*45)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("i","xi","xi+1","er"))
    print("-"*45)

    # delcaramos el contador de iteraciones
    i=1
    while True:
        
        Xi1=metodo(Xi)
        # obtenemos el error relativo teniendo en cuenta 
        # el el valor actual y anterior de xi+1
        er=abs((Xi1-Xi1_ant)/Xi1)

        print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format(i,round(Xi,6), round(Xi1,6), round(er,6)))
            
        # vamos combirtiendo el valoor actual de xi+1 en el valor xi+1 anterior
        # para usarlo en el la iteracion siguiente
        Xi1_ant=Xi1
        
        # xi+1 pasa a ser xi para evaluarlo en la proxima iteracion
        Xi=Xi1
        
        # verificampos que el error relativo sea menor al error esperado
        if er<es:
            break # si lo enterior ocurra se detendra el cilo 

        # vamos contando las iteraciones que ocurren 
        i+=1

    print("-"*45)

    print(" la raiz de la funcion es:",Xi)
    pass




# funcion principal -------------------------------------------------------------------------- 
def run():
    
    # usamos un ciclo infinito para repetir el programa hasta bque el usuario lo solicite
    while True:
        print("\n Encontrar la raiz de  ")
        print("      F(x)= ln(x) + x - 5   ")

        # solicitamos a usuario el metodo que wuiere utilizar
        print("\n escoja el metodo con cual evaluar ")
        print(" 1 para Punto fijo ")
        print(" 2 para Newton-Raphson ")
        m=int(input(" dijite el correspondiente al metodo:"))
        # validamos que el usuario ingrese solo las opciones correspondientes 
        while m<1 or m>2:
            print(" ingrese 1 o 2")
            m=int(input(" ingresa el metodo nuevamente: "))

        Xi=int(input("\n Dijite el valor inicial de xi: "))

        # solicitamos ala usuario la cantidad de cifras significativas para el error esperado
        print("\n # error esperado ")
        n=int(input(" ingrese la cantidad se cifras significativas para Es:"))
        if n<=2:
            n=3
        es=(0.5*(10**(2-n))) # calculamos el error esperado con base a las cifras significativas ingresadas 
        print(" error esperado:",es)

        # evaluamos la funcion usando el metodo selecionado por el usuario 
        if m==1:
            print("\n Metodo de Punto fijo ")
            evaluacion(fixed_point, Xi, es)
        else:
            print("'n Metodo de Newton-Raphson ")
            evaluacion(Newton_Raphson, Xi, es)

        r=int(input("ingrese 1 para repetir el programa :"))
        if r!=1:
            break
    
if __name__=="__main__":
    run()
