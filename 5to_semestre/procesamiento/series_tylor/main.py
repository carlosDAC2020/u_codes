# Carlos Daniel Agamez T00059006
# lenguaje de programacion : Python 3.9.5
from math import sin,cos

# funcion para obtener el factrial de un numero 
def factorial(num:int) ->int: 
    fact=1
    while num>1:
        fact*=num
        num-=1
    return fact

# declaramos la serie de tylor obtenida como una funcion a la cual le pasamos los parametros h y x
def serie_tylor(h:float, x:float) -> float: 
    fx = (sin(x**2)) + (2*x*cos(x**2))*h + (( 2*cos(x**2) - 4*x**2*sin(x**2)) / factorial(2))*(h**2) + (( -12*x*sin(x**2) - 8*(x**3)*cos(x**2) ) / factorial(3))*(h**3)
    return fx

def run():
    print(" obtenemos las cigfras significativas \n para el error espersdo ")

    n=int(input(" ultimo numero de su codugo T000:"))
    if n<=2: # validamos que el numero de cifras significativas para el error espersdo no sea menor a 3
        n=3

    Es= (0.5*(10**(2-n))) # obtenemos el error esperado con la formula de Scarborough

    # variables proporcionadas en ele enunciado
    xi=0.5
    xi_1=1
    va=0 # aproximacion anteriro
    h=0 # el paso con ele que se evalua la funcion es inicialmente cero

    rep=0
    while True:
        ve=serie_tylor(h,xi) # aproximacion actual
        ve=round(ve,n)

        Er= abs(((ve-va)/ve)*100) # obtenemos el error relativo

        if Er<Es:# evaluamos que el error relativo sea menor al espersdo para detener el ciclo 
            break
        
        va=ve # hacemos que el valor actual se la serie sea el anterior para evaluar el error relativo
        h+= xi_1 - xi # aumentamos el valor de h pra seguir evaluando la serie 
        rep+=1 # vamos contando la cantidad de evaluaciones realizadas 

    print("valor actual:",ve)
    print("valor anterior:",va)
    print("error relativo:",Er)
    print("error esperado:",Es)
    print("cantidad de evaluaciones realizadas:",rep)

    # NOTA : entre mayor numero de n mas tardara el ciclo en hacer la evaluacion 
    
if __name__=="__main__":
    run()