 
import numpy as np  # usamos numpy para usar las funciones trigonometricas 
from random import uniform # lo usamos para obtener numeros flotantes aleatorios en un intervalo dado
from math import sqrt # lo usamos para sacar la raiz cuadrada 

"""
declaramos las funciones evaluar y a partisr de estas obtenemos:
    # exprecion de la funcion 
    # derivadas 
    # exprecion para el metodo de punto fijo 
"""
# punto 3.2.1 -------------------------------------------------------------------------
def f_p2(a,D=None): # funcion
    if D==None:
        D=55 #30
    A = 89*np.sin(np.radians(11.5))
    B = 89*np.cos(np.radians(11.5))
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D) 

    return (A*np.sin(np.radians(a))*np.cos(np.radians(a))) + (B*(np.sin(np.radians(a)))**2) - (C*np.cos(np.radians(a))) - (E*np.sin(np.radians(a)))
    # f(a) = Asen(a)cos(a) + Bsen^2(a) - Ccos(a) - Esen(a)

def df_p2(a, D=None): # derivada 
    if D==None:
        D=55
    A = 89*np.sin(np.radians(11.5))
    B = 89*np.cos(np.radians(11.5))
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D)


    return (A*np.cos(np.radians(a))*np.sin(np.radians(a))) + ((2*B)*((np.sin(np.radians(a)))**2)*(np.cos(np.radians(a)))) - (C*np.sin(np.radians(a))) - (E*(np.cos(np.radians(a)))*(np.sin(np.radians(a))))

    # f'(a) = 𝑨𝒄𝒐𝒔(𝜶)𝒔𝒆𝒏(𝜶) + 2𝑩𝒔𝒆𝒏^2(𝜶)𝒄𝒐𝒔(𝜶) - 𝑪𝒔𝒊𝒏(𝜶) - 𝑬𝒄𝒐𝒔(𝜶)𝒔𝒆𝒏(𝜶)


def p2_punto_fijo(a, D=None): # forma de punto fijo 
    if D==None:
        D=55
    A = 89*np.sin(np.radians(11.5))
    B = 89*np.cos(np.radians(11.5))
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D)

    num = C * np.cos(np.radians(a)) + E * np.sin(np.radians(a))
    den = A * np.cos(np.radians(a)) + B * np.sin(np.radians(a))**2
    return num / den
    # 𝑔(𝜶) = [𝐶cos(𝜶) + 𝐸sen(𝜶)] / [𝐴cos(𝜶) + 𝐵sen^2(𝜶)]

# punto 3.2.2 -------------------------------------------------------------------------
def f_p3(h): # funcion 
    return 12.4 - (10*((0.5*np.pi) - np.arcsin(h) - h*((1-h**2)**0.5))) 

def df_p3(h): # derivada
    return 20 * sqrt(1-h**2) 

def p3_punto_fijo(h): # forma del punto dijo 
    return np.sin(0.5*np.pi - (12.4 - h)/10 - h*np.sqrt(1 - h**2)) 



# metodos de evaluacion
def Newton_Raphson( x,f,df): 
  return x -((f(x))/(df(x)))

def biseccion(f, xl, xu):
  return (xl+xu)/2

def falsa_posicion(f, xl, xu): 
  return xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))

    
def evaluador_BC_FP(f,xl,xu, es, mt):

    # dependiendo el metoso pasado como parametro hacemos la variable igial a la formula del metodo correspondiente
    metodo = biseccion if mt=="BC" else falsa_posicion

    # valor auxilar anterior de x
    xrant=0
    
    # numero de iteraciones
    i=1

    print("-"*34)
    print("|{:^10}|{:^10}|{:^10}|".format("iter", "raiz apr", "ER"))
    print("-"*34)
    while True:
        # aplicamos la formula del metodo correspondiente
        xr=metodo(f,xl,xu)
        
        # obtenemos el error relativo y lo vamos añadiendo a la lista de valores para graficarlo despues 
        er=abs(((xr-xrant)/xr)*100)
        # vamos imprimiendo los resultados de la evaluacion 
        print("|{:^10}|{:^10}|{:^10}|".format(i, round(xr,5), round(er,5)))
         
        # vamos guardando xr en una variable enterior 
        xrant=xr

        if mt=="FP":
            if f(xl)*f(xu)<0:
                xu=xr
            elif f(xl)*f(xu)>0:
                xl=xr
            if er<es:
                break
        else:
            if f(xl)*f(xr)<0:
                xu=xr
            elif f(xl)*f(xr)>0:
                xl=xr
            if er<es:
                break

        # vamos sumnado 1  las iteraciones 
        i+=1
    print("-"*34)
    print(" raiz : ",xr)
  
        

        

#---------------------------------------------------------------------------------------------------------------


def evaluador_PF_NR(metod, xi, es, name_metod, f=None, df=None):

    """
    funcion que evalua el metodo conrrespondiente ya sea:
        # punto fijo 
        # Newton-Raphson 

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

        NOTA
        en caso de que un parametro no sea obligatorio para alguno de las metodos 
        ingrese un 0 en su lugar, 
        para los metodos no obligatorios se les dara un valor predeterminado de none

    """

    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    # realizamos la evaulacion de la funcion por medio del metodo correspondiente
    print("-"*34)
    print("|{:^10}|{:^10}|{:^10}|".format("iter", "raiz apr", "ER"))
    print("-"*34)
    while True:
        # evaluamos xi con el metodod correspondiente 
        if name_metod=="PF": # cuando se evalua el metodod de punto fijo 
            xi1 = metod(xi)
        else: # cuando se evalua el metodo de Newton-Raphson 
            xi1 = metod(xi,f,df)
        
        # obtenemos el error relativo
        er=abs((xi1-xi1_ant)/xi1)
        # vamos imprimiendo los resultados de la evaluacion 
        print("|{:^10}|{:^10}|{:^10}|".format(i, round(xi1,5), round(er,5)))
        # guardamos el valor enterior 
        xi1_ant=xi1
        # al evaluarse el metodo de punto fijo y Newton-Raphson se hara la siguiente asignacion
        xi=xi1
        
        # criterio de parada de la evaulacion 
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    print("-"*34)
    print(" raiz : ",xi1)


def run():
  print(" Parcial \n")
    
  print(" Escoga la funcion a evaluar :")
  print(" 1) f(a) = Asen(a)cos(a) + Bsen^2(a) - Ccos(a) - Esen(a) ")
  print(" 2) f(h) = 12.4 - 10[0.5pi - arcsen(h) - h(1 - h^2)^1/2]")
  f_op = int(input("----->"))
  while f_op<1 or f_op>2:
    print(" avlor ingresado no valido!!\n dijite su opcion otra ves ")
    f_op = int(input("----->"))
    
  # asiganmos las funciones correpondientes a variables auxiliares 
  if f_op==1:
    fx = f_p2
    df = df_p2
    f_pf = p2_punto_fijo
  else:
    fx = f_p3
    df = df_p3
    f_pf = p3_punto_fijo

    

  print("\n metodos para evaluar ")
  print(" 1) punto fijo ")
  print(" 2) Newton-Raphson ")
  print(" 3) Falsa Posicion ")
  print(" 4) Biseccion")
  m_op = int(input(" digite el numero de la opcion: "))
  while m_op<1 or m_op>4:
      print(" valor ingresado invalido")
      m_op = int(input(" digite el numero de la opcion: "))


  print("\n intervalo de evaluacion ")
  xi = float(input(" limite inferior:"))
  xu = float(input(" limite superior:"))
  while xu<xi:
      print(" limite superior no puede ser mayor al inferior!")
      xu = float(input(" limite superior:"))

  # valor inical para evaluar los metodos abiertos 
  xi=uniform(xi, xu)
  # obtenemos el error esperado 
  cs=int(input(" cifras significativas :"))
  es = (0.5*(10**(2-3))) if cs<=2 else (0.5*(10**(2-cs)))



    
  # cuando el metodo es habierto 
  
  if m_op<3:
      if m_op==1:
        # evaluacion del metodod de punto fijo 
        print(" punto fijo ")
        evaluador_PF_NR(f_pf,xi,es, "PF")
      else:
        # evaluacion del metodod de  Newton-Raphson 
        print(" Newton_Raphson")
        evaluador_PF_NR(Newton_Raphson, xi, es, "NR", fx, df)
  else: 
    if m_op==3:
      # en caso se evalue con el metodo de falsa posicion
      print(" Falsa Posicion")
      evaluador_BC_FP(fx, xi, xu, es, "FP")
    else:
      # en caso se evalue con el metodo de Biseccion 
      print(" Biseccion")
      evaluador_BC_FP(fx, xi, xu, es, "BC")
    
      
  
if __name__=="__main__":
    run()

    
    
    
    

