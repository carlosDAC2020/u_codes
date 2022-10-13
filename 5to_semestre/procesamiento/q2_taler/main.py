
# TALLER 
# Maria Angeles Gil Arrieta T00061111
#Sayuri Julieth Marmol Matute T00056614
# Carlos Daniel Agamez T00059006
# lenguaje de programacion : Python 3.9.5
# Nrc : 1457
import matplotlib.pyplot as plt 
import numpy as np 
import pylab as pl
from random import randint

"""
declaramos las funciones evaluar y a partisr de estas obtenemos:
    # exprecion de la funcion 
    # derivadas 
    # exprecion para el metodo de punto fijo 
"""
# funcion 1
f1 = lambda x: np.log(x) + x - 5
df1 = lambda x: (1/x) + 1
f1_punto_fijo = lambda x: -np.log(x) + 5 

# funcion 2
f2 = lambda x: 2*(2.7182**(-x)) - (4*x)  
df2 = lambda x: -2*(2.7182**(-x)) - 4
f2_punto_fijo = lambda x: (2*2.7182**(-x) )/4

# funcion 3
f3 = lambda x: (2.7182**(-x)) - x 
df3 = lambda x: -(2.7182**(-x)) - 1
f3_punto_fijo = lambda x: 2.7182**(-x)

"""
declramos un registro de los resultados 
que obtendremos al evaluar las funciones 
"""
funciones=[
    # registro de la funcion 1
    {
        "funcion":"f(x) = ln(x) + x - 5",
        "f(x)":f1,
        "f'(x)":df1,
        "m_punto_fijo":f1_punto_fijo
    },
    # registro funcion 2
    {
        "funcion":"f(x) = 2e^-x - 4x",
        "f(x)":f2,
        "f'(x)":df2,
        "m_punto_fijo":f2_punto_fijo
    },
    # registro de la funcion 3
    {
        "funcion":"f(x) = e^-x - x",
        "f(x)":f3,
        "f'(x)":df3,
        "m_punto_fijo":f3_punto_fijo
    }
]

# registro de lostas de errores relativos
lists_errores_r = {
    "punto_fijo":[],
    "Newton-Raphson":[],
    "Secante":[],
    "Biseccion":[]
}

# registro de listas de promedios de errores relativos
promedios_errores = {
    "p_punto_fijo":[],
    "p_Newton-Raphson":[],
    "p_Secante":[],
    "p_Biseccion":[]
}

#---------------------------------------------------------------------------------------------------------------

# metodod de Newton-Raphson
Newton_Raphson =  lambda x,f,df: x -((f(x))/(df(x)))
# metodo de la secante 
Secante = lambda x1, x2, f: x2 - (( f(x2)*(x1-x2) ) / ( f(x1) - f(x2) ))
# Biseccion
def biseccion(xl,xu, es, f):
    # craemos este diccionario y lista auxiliar para irguaradando los resultado de la evaluacion del metodo 
    list_er=[]
    dict_aux={
        "iter":0,
        "errores_r":[],
        "raiz":0.0
   }
     
    # contador de iteraciones 
    i=1
    # variable que ira almacenado los valores anteriores de las evauaciones 
    xrant=0

    while True:

        # aplicamos la formula de la biseccion
        xr=(xl+xu)/2
        
        # obtenemos el error relativo
        er=abs(((xr-xrant)/xr)*100)

        # vamos guardando los errores obtenidos en una lista auxiliar
        list_er.append(er)

        xrant=xr

        if f(xl)*f(xr)<0:
            xu=xr
        elif f(xl)*f(xr)>0:
            xl=xr
        if er<es:
            raiz=xr
            break

        i+=1

    # guardamos los resultados de la evaluacion en el diccionario auxiliar
    dict_aux["iter"]=i
    dict_aux["errores_r"]=list_er
    dict_aux["raiz"]=raiz

    # retornamos el registro de la evaluacion 
    return dict_aux

#---------------------------------------------------------------------------------------------------------------

def evaluator_open_metod(metod, xi, es, name_metod, f=0, df=0, x2=0 ):
    """
    funcion que evalua el metodo conrrespondiente ya sea:
        # punto fijo 
        # Newton-Raphson 
        # secante

    esata funcion recive algunos parametros necesarios para la evaluacion segundo el metodo
    en cuestion las esenciales seran :
        ---------- obligatorios en los 3 ---------------------------------- 
        metod: funcion que contendra la formula del metodo correspondiente segun la funcion
        xi: valor inical de evaluacion
        es: error esperado
        name_metodo: especifica el metodo usado en el moneto de ejecucion de la funcion
        
        ---------- obligatorios en Newton-Raphson ---------------------------
        f : formula general de la funcion a evaluar
        df : formula de la derivada de la funcion a evaluar

        --------- obligatorios en en secante --------------------------------
        x2 : segundo valor inicial para evaluar la funcion usando el metodode la secante

        NOTA
        en caso de que un parametro no sea obligatorio para alguno de las metodos 
        ingrese un 0 en su lugar, 
        para los metodos no obligatorios se les dara un valor predeterminado de 0

    """
    # craemos este diccionario y lista auxiliar para irguaradando los resultado de la evaluacion del metodo 
    list_er=[]
    dict_aux={
        "iter":0,
        "errores_r":[],
        "raiz":0.0
    }
    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    while True:
        # evaluamos xi con el metodod correspondiente 
        if name_metod=="PF": # cuando se evalua el metodod de punto fijo 
            xi1 = metod(xi)
        elif name_metod=="NR": # cuando se evalua el metodo de Newton-Raphson 
            xi1 = metod(xi,f,df)
        else:                   # cuando se evalua el metodo de la secante 
            xi1= metod(xi, x2, f)
            
        # obtenemos el error relativo
        er=abs((xi1-xi1_ant)/xi1)
        # vamos guardando los errores obtenidos en una lista auxiliar
        list_er.append(er)
        # guardamos el valor enterior 
        xi1_ant=xi1

        # al evaluarse el metodo de punto fijo y Newton-Raphson se hara la siguiente asignacion
        if name_metod=="PF" or name_metod=="NR":
            xi=xi1
        else: # esto se ejecutara solamente al evaluar el metodo de la secante 
            xi=x2
            x2=xi1
        
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    

    # guardamos los resultados de la evaluacion en el diccionario auxiliar
    dict_aux["iter"]=i
    dict_aux["errores_r"]=list_er
    dict_aux["raiz"]=xi


    # retornamos el registro de la evaluacion 
    return dict_aux
#----------------------------------------------------------------------------------------------------------------

def list_length_correction(l1, l2, l3):
     """
    toma como parametros  listas de difernte tamaño 
    las da la misma longitud teniendo en cuenta la lista de mayor longitud
    y les asigana a los indices sin valor el numero 8
    """
     ltder={
        len(l1):l1,
        len(l2):l2,
        len(l3):l3,
    }

     len_list=[len(l1), len(l2), len(l3)]
     len_list.sort()
    
     for i in range(len_list[2]):
        if i>len_list[0]-1:
            ltder[len_list[0]].append(0)
        if i>len_list[1]-1:
            ltder[len_list[1]].append(0)
    
     l1 = ltder[len_list[0]]
     l1 = ltder[len_list[1]]
     l1 = ltder[len_list[2]]

# ibtenemos la lista de promedio de 3 listas 
proms_errores_r = lambda l1, l2, l3, tam:[ ( l1[i] + l2[i] + l3[i] ) /3 for i in range(tam)]


#---------------------------------------------------------------------------------------------------------------
def run():
    print(" Evaluaremos las funciones:")
    print(" f1(x) = ln(x) + x - 5")
    print(" f2(x) = 2e^-x - 4x")
    print(" f3(x) = e^-x - x")

    print("\nn usando los metodos de ")
    print(" # punto fijo ")
    print(" # Newton-Raphson ")
    print(" # Secante")
    print(" # Biseccion")

    # grafica de las funciones 
    X = np.linspace(-1, 5, 256, endpoint=True)
    C, S = np.cos(X), np.sin(X)

    plt.plot(X, f1(X), color="blue", linewidth=1.0, linestyle="-", label="f1(x) = ln(x) + x - 5")
    plt.plot(X, f2(X), color="green", linewidth=1.0, linestyle="-", label="f2(x) = 2e^-x - 4x")
    plt.plot(X, f3(X), color="red", linewidth=1.0, linestyle="-", label="f3(x) = e^-x - x")
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

    
    print("\n intervalo de evaluacion de las funciones ")
    li = int(input(" ingresa limite inferior:"))
    ls = int(input("inghresa limite superior:"))
    while ls<li:
        print(" limite superior no puede ser mayor al inferior!")
        ls = int(input("inghresa limite superior:"))

    Xi=randint(li, ls)

    # solicitamos ala usuario la cantidad de cifras significativas para el error esperado
    print("\n # error esperado ")
    n=int(input(" ingrese la cantidad se cifras significativas para Es:"))
    if n<=2:
        n=3
    es=(0.5*(10**(2-n))) # calculamos el error esperado con base a las cifras significativas ingresadas 
    print(" error esperado:",es)
    i=1

    # evaluacion de los metodos 
    for func in funciones:

        # hacemos la siguiente validacion para evitar que python tenga problemas al  ln(0) = infinito en la f1 
        if li==0 or Xi==0:
            if li==0:
                li+=0.1
            elif Xi==0:
                Xi+=0.1 

        # evaluacion del metodod de punto fijo 
        r_pf = evaluator_open_metod(func["m_punto_fijo"],Xi,es, "PF")
        # guardamos la lista de los errores obtenidos en su correspondiente registro
        lists_errores_r["punto_fijo"].append(r_pf["errores_r"]) 
        
        # evaluacion del metodod de  Newton-Raphson 
        r_Nr = evaluator_open_metod(Newton_Raphson, Xi, es, "NR", func["f(x)"], func["f'(x)"])
        lists_errores_r["Newton-Raphson"].append(r_Nr["errores_r"])

        # evaluacion del metodod de la Secante 
        r_Sc = evaluator_open_metod(Secante, li, es, "SC", func["f(x)"], func["f'(x)"], ls)
        lists_errores_r["Secante"].append(r_Sc["errores_r"])

        # evaluacion del metodod de Biseccion 
        r_Bc = biseccion(li, ls, es, func["f(x)"])
        lists_errores_r["Biseccion"].append(r_Bc["errores_r"])
       
        print("\n resultados de  la fincion",i,"-"*35)
        print("     ",func["funcion"])

        print("-"*44)
        print("|{:^18}|{:^10}|{:^12}| ".format("Metodo","iter","raiz"))
        print("-"*44)
        print("|{:^18}|{:^10}|{:^12}| ".format("Punto Fijo", r_pf["iter"], round(r_pf["raiz"],7)))
        print("|{:^18}|{:^10}|{:^12}| ".format("Newton-Raphson", r_Nr["iter"], round(r_Nr["raiz"],7)))
        print("|{:^18}|{:^10}|{:^12}| ".format("Secante", r_Sc["iter"], round(r_Sc["raiz"],7)))
        print("|{:^18}|{:^10}|{:^12}| ".format("Biseccion", r_Bc["iter"], round(r_Bc["raiz"],7)))
        print("-"*44)
        
        i+=1

    # obtenemos los promedios de los errores relativos por cada metodo 
    l_er_pf = lists_errores_r["punto_fijo"]
    list_length_correction(l_er_pf[0], l_er_pf[1], l_er_pf[2])
    promedios_errores["p_punto_fijo"] = proms_errores_r(l_er_pf[0], l_er_pf[1], l_er_pf[2], len(l_er_pf[2]))

    l_er_Nr = lists_errores_r["Newton-Raphson"]
    list_length_correction(l_er_Nr[0], l_er_Nr[1], l_er_Nr[2])
    promedios_errores["p_Newton-Raphson"] = proms_errores_r(l_er_Nr[0], l_er_Nr[1], l_er_Nr[2], len(l_er_Nr[2]))

    l_er_Sc = lists_errores_r["Secante"]
    list_length_correction(l_er_Sc[0], l_er_Sc[1], l_er_Sc[2])
    promedios_errores["p_Secante"] = proms_errores_r(l_er_Sc[0], l_er_Sc[1], l_er_Sc[2], len(l_er_Sc[2]))

    l_er_Bc = lists_errores_r["Biseccion"]
    list_length_correction(l_er_Bc[0], l_er_Bc[1], l_er_Bc[2])
    promedios_errores["p_Biseccion"] = proms_errores_r(l_er_Bc[0], l_er_Bc[1], l_er_Bc[2], len(l_er_Bc[2]))

    # ajustamos la longitud de las listas de los promedios para mostrarlos mejor en la grafica
    len_list_p_er = [len(promedios_errores["p_punto_fijo"]), len(promedios_errores["p_Newton-Raphson"]), len(promedios_errores["p_Secante"]), len(promedios_errores["p_Biseccion"])]
    len_list_p_er.sort()
    # lvolvemos las listas de los promedios de errores relativos del mismo tamaño
    for p in promedios_errores.values():
        while len(p) < len_list_p_er[3]:
            p.append(0)

    iters = [i for i in range(1,len_list_p_er[3]+1)]

    # Grafica
    fig, ax = plt.subplots()
    plt.grid()
    ax.set_title('Iteraciones VS Error rekativo', loc = "left", fontdict = {'fontsize':14, 'fontweight':'bold', 'color':'tab:blue'})
    ax.plot(iters, promedios_errores["p_punto_fijo"], label = 'punto fijo', color = 'tab:blue')
    ax.plot(iters, promedios_errores["p_Newton-Raphson"], label = 'Newton-Raphson', color = 'tab:green')
    ax.plot(iters, promedios_errores["p_Secante"], label = 'Secante', color = 'tab:orange')
    ax.plot(iters, promedios_errores["p_Biseccion"], label = 'Biseccion', color = 'tab:red')
    ax.legend(loc = 'upper right')
    ax.grid(axis = 'y', color = 'gray', linestyle = 'dashed')
    ax.set_xlabel("Iteraciones")
    ax.set_ylabel("Error relativo")
    plt.show()

    print(" Conclusion ")
    print(" al evaliuar las funciones con los 4 metodos propuestos \n y encontrar las raices correspondientes de las funciones evaluadas")
    print(" los metodos del mas a manos esfectivo osn ")
    print(" 1 Newton-Raphson: es que menos itwraciones nececita")
    print(" 2 Secante")
    print(" 3 punto_fijo")
    print(" 4 Biseccion")

if __name__=="__main__":
    run()