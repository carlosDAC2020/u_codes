f = lambda x : x**(2/4) - (2*x) + 3

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

    print("la reiz es ",raiz)

    # retornamos el registro de la evaluacion 
    return dict_aux

biseccion(1,3,0.005,f)