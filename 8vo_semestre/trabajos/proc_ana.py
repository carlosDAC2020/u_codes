import matplotlib.pyplot as plt 
import numpy as np 
import pylab as pl


# metodos
def Newton_Raphson(xi, es, f, df):
    """
    Implementación del método de Newton-Raphson para encontrar una raíz de una función.

    Args:
    - xi (float): Valor inicial para comenzar la iteración.
    - es (float): Tolerancia para el error relativo, define la precisión deseada.
    - f (function): Función cuya raíz se está buscando.
    - df (function): Derivada de la función f.

    Returns:
    - float: Aproximación de la raíz encontrada.

    La función realiza iteraciones utilizando el método de Newton-Raphson hasta que el error relativo sea menor que la tolerancia es.
    Imprime una tabla con los resultados de cada iteración.
    """
    # variable que ira almacenando los valores anteriores de las evaluaciones
    xi1_ant = 0
    # contadora de iteraciones
    i = 1
    print("-" * 44)
    print("|{:^18}|{:^10}|{:^12}| ".format("iteracion", "xr", "es"))
    print("-" * 44)
    while True:
        # cuando se evalua el metodo de Newton-Raphson
        xi1 = xi - ((f(xi)) / (df(xi)))
        # obtenemos el error relativo
        er = abs((xi1 - xi1_ant) / xi1)
        # vamos imprimiendo los resultados
        print("|{:^18}|{:^10}|{:^12}| ".format(round(i, 5), round(xi1, 5), round(er, 5)))
        # guardamos el valor anterior
        xi1_ant = xi1
        # reasignamos el valor de xi
        xi = xi1
        if er < es:
            break
        # vamos contando las iteraciones
        i += 1
    print("-" * 44)
    print(" La raiz de la funcion es aproximadamente:", xi1)

    


def biseccion(xl, xu, es, f):
    """
    Implementación del método de Bisección para encontrar una raíz de una función.

    Args:
    - xl (float): Límite inferior del intervalo inicial.
    - xu (float): Límite superior del intervalo inicial.
    - es (float): Tolerancia para el error relativo, define la precisión deseada.
    - f (function): Función cuya raíz se está buscando.

    Returns:
    - float: Aproximación de la raíz encontrada.

    La función realiza iteraciones utilizando el método de Bisección hasta que el error relativo sea menor que la tolerancia es.
    Imprime una tabla con los resultados de cada iteración.

    """
    # contador de iteraciones
    i = 1
    # variable que irá almacenando los valores anteriores de las evaluaciones
    xrant = 0

    print("-" * 44)
    print("|{:^18}|{:^10}|{:^12}| ".format("iteracion", "xr", "es"))
    print("-" * 44)
    while True:
        # aplicamos la formula de la bisección
        xr = (xl + xu) / 2
        # obtenemos el error relativo
        er = abs(((xr - xrant) / xr) * 100)
        # vamos imprimiendo los resultados
        print("|{:^18}|{:^10}|{:^12}| ".format(round(i, 5), round(xr, 5), round(er, 5)))

        # vamos guardando el valor anterior
        xrant = xr

        if f(xl) * f(xr) < 0:
            xu = xr
        elif f(xl) * f(xr) > 0:
            xl = xr
        if er < es:
            raiz = xr
            break

        i += 1

    print("-" * 44)
    print(" La raiz de la funcion es aproximandamente:", raiz)


" funcion del metodo de la falsa posision "
#@execution_time
def falsa_posicion(xl, xu, es,f): 
    # valor auxilar anterior de x
    xrant=0
    # raiz de la funcion 
    raiz=0
    # numero de iteraciones
    i=1
    while True:
        print("\n\n iteraciones ",i)
        print("xl=",xl)
        print("xu=",xu)
        print(f'f({xl})={f(xl)}')
        print(f'f({xu})={f(xu)}')
        xr=xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))
        print(f'xr={xu}-(({f(xu)}*({xl}-{xu}))/({f(xl)}-{f(xu)}))={xr}')
        er=abs(((xr-xrant)/xr)*100)
        print(f'er=|(({xr}-{xrant})/{xr})*100|={er}')
        
        xrant=xr

        if f(xl)*f(xu)<0:
            xu=xr
            print('f(xl)*f(xu)<0')
            print(f'xu={xr}')
        elif f(xl)*f(xu)>0:
            xl=xr
            print('f(xl)*f(xu)>0')
            print(f'xl={xr}')
        if er<es:
            raiz=xr
            print(" la raiz de la ecuacion es:",raiz)
            break

        i+=1
        
    

# grafica
def grafica(f,formula):
    # grafica de las funciones 
    X = np.linspace(-1, 5, 256, endpoint=True)
    C, S = np.cos(X), np.sin(X)

    plt.plot(X, f(X), color="red", linewidth=1.0, linestyle="-", label=f'{formula}')
    pl.legend(loc='upper right')

    plt.title("Funciones a Evaluar")
    plt.xlabel("X")
    plt.ylabel("Y")

    ax = pl.gca()  # gca stands for 'get current axis'
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.spines['bottom'].set_position(('data',0))
    ax.yaxis.set_ticks_position('left')
    ax.spines['left'].set_position(('data',0))

    plt.show()


n=3 # cifras significativas 
if n<=2:
    n=3
es=(0.5*(10**(2-n))) # calculamos el error esperado con base a las cifras significativas ingresadas 
print(" error esperado:",es)

# RESTRICCIONES 
# evaluar siempre con 3 cifras significativas si el ejercicio propone error esperado
# si no c propone usar n=2 

# ------- ejrcicios a resolver ----------------  
# METODOS CERRADOS: pags 110  y 111 
""" 5.6
    Grafico
    Biseccion 3 iter li=0,5 y ls=2
    falsa posicion  3 iter li=0,5 y ls=2
""" 
f1 = lambda x : (x**2)-0.7
df1 = lambda x : 2*x
#print("\n\n 5.6")
#print(" error esperado:",es)
#print(" xi=",0.5," xu=",2)
#grafica(f1,'f(x)=(x^2)-0.7')
#print("prueba biseccion")
#biseccion(0.5,2,es,f1)
#print("prueba falsa posicion")
#falsa_posicion(0.5,2,es,f1)
# La raiz de la funcion es aproximandamente: 0.836660033081774
"""
    5.12
    Biseccion 
    encontrar maximo de la funcion 
    li=o y ls=1 er>0,05 n=3
""" 
fun =lambda x : (-2*(x**6))-(1.5*(x**4))+(10*x)+2
f2 = lambda x : (-12*(x**5)) - (6*(x**3)) + 10
#print("\n\n 5.12")
#print(" error esperado:",es)
#print(" xi=",0," xu=",1)
#grafica(fun,'f(x)=(-2*(x^6))-(1.5*(x^4))+(10*x)+2')
#grafica(f2,'f(x)=(x^2)-0.7')
#print("prueba biseccion")
#biseccion(0,1,es,f2)
"""
5.17 
 Falsa posiscion hacer 
 iteraciones : 3 (er por iteracion) 
 valores : 
"""
#print("\n\n 5.17")
#print(" error esperado:",es)
#print(" xi=",0," xu=",3)
pi=4.1416
v = lambda h : ((pi*(h**2))*((6-h)/3))-30
#grafica(fun,'f(x)=((pi*(h**2))*((6-h)/3))-30')
#print("prueba falsa posicion")
#falsa_posicion(0,3,0.5,v)
# la raiz de la ecuacion es: 2.4871972246766334
u = lambda h : ((pi*(h**2))*((6-h)/3))
#print(u(2.4871972246766334))

# METODOS ABIERTOS(Newton-Raphson): pags 135 y 136  
""" 6.11
    Newton-Raphson 
    probar co los valores iniciales 2, 6 y 8
"""
f = lambda x:((2.7182**(-0.5*x))*(4-x))-2
df = lambda x:((x*(2.7182**(-0.5*x)))-(6*(2.7182**(-0.5*x))))/2
#print("\n Conjetura a:",2)
#print(" error esperado:",es)
#print(" xi=",2)
#Newton_Raphson(2,es,f,df)
#print("\n Conjetura b:",6)
#print(" error esperado:",es)
#print(" xi=",6)
#Newton_Raphson(6,es,f,df)
#print("\nConjetura c:",8)
#print(" error esperado:",es)
#print(" xi=",6)
#Newton_Raphson(8,es,f,df)
""" 6.19
    Newton-Raphson 
    3 iter er*iter 
    li=0 ls=R
"""
pi=4.1416
v = lambda h : ((pi*(h**2))*((6-h)/3))-30
dv= lambda h : (-pi*(h**2))+(4*pi*h)
print(" error esperado:",es)
print(" xi=",6)
Newton_Raphson(3,es,v,dv)
u = lambda h : ((pi*(h**2))*((6-h)/3))
print(u(2.4871972246766334))
#print("\n\n 6.11")
#print("prueba newthon rapson")
#Newton_Raphson(1,es,f,df)

#print("prueba biseccion")
#biseccion(0,1,es,f)
