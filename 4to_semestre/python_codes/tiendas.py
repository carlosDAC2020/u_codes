"""
 Suponga que una empresa tiene 7 sucursales distribuidas en el país.
 y se ingresan la cantidad de ventas realizadas en cada mes en cada sucursal 
 durante un año a partir de estos datos realizanos un analisi de las ventas y
 obtenemosm lo siguiente

se imprimira:
    a. Cual fue la sucursal que mas vendio en todo el año
    b. Cual fue la sucursal q mas vendio en cada mes 
    c. Cual fue el mes en que mas vendio cada sucursal
    d. promedio de ventas de tda la empresa por cada mmes 
    e. promedio de ventas en todo el año de cada sucursal 
"""

from random import randint


#--------------------- FUNCIONES AUXILIARES -----------------------------------------------

def ingreso_ventas(): 
    
    matriz=[[0 for c in range(7)]for f in range(12)]
    
    for f in range(12):
        for c in range(7):
            matriz[f][c]=randint(10,100) 
 
    return matriz


def suc_may_ventas(ventas): 
    may_ventas=0
    sucursal_may_ventas=0
    for c in range(7):
        sum=0
        for f in range(12):
            sum+=ventas[f][c]
        if sum>may_ventas:
            may_ventas=sum
            sucursal_may_ventas=c+1

    print(" la sucursal con mayor numero de ventas en ntod el año fue ")
    print("la sucursal ",sucursal_may_ventas," con un total de ",may_ventas," ventas")

def suc_vent_x_mes(ventas,meses): 

    # lista que almacena las sucursales con mayor numero de ventas por mes
    list_sucs_vents=[]
    
    # declaramos una lista donde se almacenen los elementos amyores de cada fila
    may_elmts_f=[]
    
    # utilizamos un bucle for para evaluar los elementos de la matiz
    for f in range(12):
        el_may_f=ventas[f][0]
         
        for c in range(7):
            if el_may_f < ventas[f][c]:
                el_may_f=ventas[f][c]
                # variable auxiliar para gyaradar la sucursal con mayor numero de centas en x mes
                suc=c
        may_elmts_f.append(el_may_f)
        list_sucs_vents.append(suc)
    # imprimimos los resultados
    print("\n mayores ventas por mes ")
    print("-"*40)
    print("|{:^12}|{:^12}|{:^12}|".format("mes","sucursal","ventas"))
    print("-"*40)
    for i in range(12):
        print("|{:^12}|{:^12}|{:^12}|".format(meses[i],list_sucs_vents[i]+1,may_elmts_f[i]))
    print("-"*40)
        

def mes_may_vents_sucs(ventas,meses): 
     # declaramos una lista donde se almacenen los elementos amyores de cada columna
     # esto seran el numero de ventas mayor de cada sucursal en el año 
    may_elmts_c=[]
    # meses con mayor ventas de cada sucursal
    meses_may_vents_sucs=[]
    # utilizamos un bucle for para evaluar los elementos de la matiz
    mes=""
    for c in range(7):
        el_may_c=ventas[0][c]
        for f in range(12):
            if el_may_c < ventas[f][c]:
                el_may_c=ventas[f][c]
                mes=meses[f]
        may_elmts_c.append(el_may_c)
        meses_may_vents_sucs.append(mes)
    # imprimimos los resultados
    print("\n mes con mayor numero de ventas por cada sucursal")
    print("-"*40)
    print("|{:^12}|{:^12}|{:^12}|".format("sucursal","mes","ventas"))
    print("-"*40)
    for i in range(7):
        print("|{:^12}|{:^12}|{:^12}|".format(i+1,meses_may_vents_sucs[i],may_elmts_c[i]))
    print("-"*40)


def prom_vents_x_mes(ventas,meses): 
    # lista donde se almacenene los promedios de cada mes
    list_prom_vents_x_mes=[]
    # usamoa un bucle for para realizar el proceso de promediado 
    for f in range(12):
        sum=0
        for c in range(7):
            sum+=ventas[f][c]
        prom= round(sum / 7,2)
        list_prom_vents_x_mes.append(prom)
    # imprimimos los resultados
    print("\n promedios de ventas por cada mes ")
    print("-"*28)
    print("|{:^12}|{:^12}|".format("mes","promedio",))
    print("-"*28)
    for i in range(12):
        print("|{:^12}|{:^12}|".format(meses[i],list_prom_vents_x_mes[i],))
    print("-"*28)
    

def prom_vents_x_sucs(ventas): 

    list_prom_vents_x_sucs=[] # lista de promedio de ventasn por sucursal

    # usamoa un bucle for para realizar el proceso de promediado 
    for c in range(7):
        sum=0
        for f in range(12):
            sum+=ventas[f][c]
        prom= round(sum / 12,2)
        list_prom_vents_x_sucs.append(prom)
    # imprimimos los resultados
    print("\n promedios de ventas por cada sucursal en en año ")
    print("-"*28)
    print("|{:^12}|{:^12}|".format("sucursal","promedio",))
    print("-"*28)
    for i in range(7):
        print("|{:^12}|{:^12}|".format(i+1,list_prom_vents_x_sucs[i],))
    print("-"*28)

#---------------------------------------------------------------------------------------------


#------------------------- FUNCION PRINCIPAL--------------------------------------------------
def analisis_ventas():
    # tupla con los meses para la imprecion de los datos 
    meses = ("Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio",
        "Agosto","Septiembre","Octubre","Noviembre","Diciembre")

    # hacemos la asigancion de la cantidad de ventas a cada sucursal
    ventas=ingreso_ventas()

    # imprimimos los datos obtenidos 
    print("{:^105}".format("TABLA GENERAL DE VENTAS"))
    print("-"*105)
    print("|{:^12}|{:^12}|{:^12}|{:^12}|{:^12}|{:^12}|{:^12}|{:^12}|  ".format("mes","sucursal 1","sucursal 2","sucursal 3","sucursal 4","sucursal 5","sucursal 6","sucursal 7"))
    print("-"*105)
    for f in range(12):
        print("|{:^12}|".format(meses[f]),end="")
        for c in range(7):
            print("{:^12}|".format(ventas[f][c]),end="")
        print("")
    print("-"*105)


    # imprimos lel analisis que se nos solicita
    print("{:^56}".format("ANALISIS DE VENTAS"))
    # a. Cual fue la sucursal que mas vendio en todo el año
    suc_may_ventas(ventas)
    # b. Cual fue la sucursal q mas vendio en cada mes 
    suc_vent_x_mes(ventas,meses)
    # c. Cual fue el mes en que mas vendio cada sucursal
    mes_may_vents_sucs(ventas,meses)
    # d. promedio de ventas de toda la empresa por cada mmes 
    prom_vents_x_mes(ventas,meses)
    # e. promedio de ventas en todo el año de cada sucursal 
    prom_vents_x_sucs(ventas)
#---------------------------------------------------------------------------------------------

analisis_ventas()



