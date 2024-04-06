

# funcion a evaluar
f = lambda x:((2.7182**(-0.5*x))*(4-x))-2
df = lambda x:(0.5*(2.7182**(-0.5*x))*x)-(3*2.7182**(-0.5*x))


# metodod de Newton-Raphson
Newton_Raphson =  lambda x,f,df: x -((f(x))/(df(x)))

def evaluator_open_metod(metod, xi, es, name_metod, f=0, df=0):
     
    """
    Evalúa un método numérico para encontrar raíces de ecuaciones.

    Args:
        metod: Función que implementa el método numérico a utilizar.
        xi: Valor inicial para la iteración.
        es: Error relativo máximo permitido para la aproximación de la raíz.
        name_metod: Nombre del método a utilizar ("PF" para Punto Fijo, cualquier otro valor para Newton-Raphson).
        f: Función f(x) para el método de Newton-Raphson.
        df: Función derivada de f(x) para el método de Newton-Raphson.
        x2: Valor adicional requerido por algunos métodos.

    """

    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    print("-"*44)
    print("|{:^18}|{:^10}|{:^12}| ".format("iteracion","xr","es"))
    print("-"*44)
    while True:
        # evaluamos xi con el metodod correspondiente 
        if name_metod=="PF": # cuando se evalua el metodod de punto fijo 
            xi1 = metod(xi)
        else : # cuando se evalua el metodo de Newton-Raphson 
            xi1 = metod(xi,f,df)
       
            
        # obtenemos el error relativo
        er=abs((xi1-xi1_ant)/xi1)

        # vamos imprimiendo los resultados
        print("|{:^18}|{:^10}|{:^12}| ".format(round(i,5), round(xi1,5), round(er,5)))
        
        # guardamos el valor enterior 
        xi1_ant=xi1

        # al evaluarse el metodo de punto fijo y Newton-Raphson se hara la siguiente asignacion
        xi=xi1
        
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    print("-"*44)
    print(" La raiz de la funcion es aproximandamente:",xi1)
    
    



def run():
    

    n=3
    if n<=2:
        n=3
    es=(0.5*(10**(2-n))) # calculamos el error esperado con base a las cifras significativas ingresadas 
    print(" error esperado:",es)
    

    # evaluacion del metodod de  Newton-Raphson 
    print("\n Metodod de Newton-Raphson (6.11)")
    print("\n Conjetura a:",2)
    print(" error esperado:",es)
    print(" xi=",2)
    evaluator_open_metod(Newton_Raphson, 3, es, "NR", f, df)
    
    print("\n Conjetura b:",6)
    print(" error esperado:",es)
    print(" xi=",6)
    evaluator_open_metod(Newton_Raphson,6,es,"NR",f,df)

    print("\nConjetura c:",8)
    print(" error esperado:",es)
    print(" xi=",6)
    evaluator_open_metod(Newton_Raphson,8,es,"NR",f,df)

    
        
if __name__=="__main__":
    run()