
# NRC 2193M 2021 - 2P
# No edite esta funcion. Solo esta imprimiendo el diccionario
from os import name


def imprimeDic(diccionario:dict):   
    print ('{:<10}{:>7}{:>7}{:>7}'.format('Nombre','Anio','Mes','Dia'))
    for clave,valor in diccionario.items():
        nombre = clave
        anio = valor[0]
        mes = valor[1]
        dia = valor[2]
        print ('{:<10}{:>7}{:>7}{:>7}'.format (nombre,anio,mes,dia))
        
fechas = {'JhonP': (2001,1, 2), 'LuisP': (2001, 1, 18), 'NicolasP':(2001, 1, 29), 'CarlosRa' : (2002,7,17),
          'Nathalia':(2004,7,6),'Josué':(2002,6,12),'Jose J': (2002,3,12),'luis' : (2004,3,26), 'DanielP': (2004,2,18),
          'Diego':(2003,8,15),'KerenHa' : (2003,7,19), 'Victoria': (2004,9,6), 'Victor' : (2004,8,10),
          'Mayerlis':(2004,6,15),'Julián': (2002,8,4), 'Adrian':(2001,1,18), 'KerenSa': (2003,7,19),
          'Christian':(2004,3,31), 'CarlosE': (2004,2,18),'Isaac': ( 2003,11,18), 'DiegoP':(2001, 1, 2 ),
          'JaimeP': (2004, 2, 18)
    }

n = (len(fechas))
print ('Cantidad de personas: ', n)
imprimeDic (fechas)

# Continúe aqui debajo con su ejercicio

# menu
go=1
while go==1:
    print("\n que desea saber ?")
    print(" 1) que personas cumplen en x mes  ")
    print(" 2) Cuántidad de  personas que cumplen en cada mes")
    print(" 3) nombres de las personas cumplen en cada mes")
    print(" 4)  persona con mayor edad")
    print(" 5) persona con menor edad?")
    # solicitamos y validamos la opcion ingresada por el usuario
    opcion=int(input("\n ingresa el numero que corresponde a la opcion elegida:"))
    while opcion<1 or opcion>5:
        print("\n el numero ingresado no esta entre las opciones ")
        opcion=int(input(" ingresa nuevamente su opcion :"))

    if opcion==1:
        # punto 1. 
        # ¿Qué personas cumplen en un mes en específico? En este
        # punto se debe preguntar al usuario por un mes (int o str)
        # y se debe imprimir la lista de personas que cumplen ese mes.

        print("\n que personas cumplen en un mes en especifico ")
        Xmes=int(input("ingrese un mes : "))
        # solicitamos el numero del un mes y con un clico for recorremos el diccionario viendo a las personas que cumplen en dicho mes
        print(" RESULTADOS DEL MES ",Xmes)
        print ('{:<10}{:>7}{:>7}'.format('Nombre','Mes','Dia'))
        for c,v in fechas.items():
            if Xmes==v[1]:  
                print ('{:<10}{:>7}{:>7}'.format (c,v[1],v[2]))

    elif opcion==2:
        # punto 2. 
        # ¿Cuántas personas cumplen en cada mes?

        # diccionario que guardara el numero de personas que cumplen en cada mes 
        cumplen_n_personas_mes={"Enero":0, "Febrero":0, "Marzo":0, "Abril":0
            , "Mayo":0, "Junio":0, "Julio":0, "Agosto":0,
                "Septiembre":0, "Octubre":0, "Noviembre":0, "Diciembre":0
                }
        i=1 # esta variable ira tomando un valor de mes difernete  en el cilo for 
        for c,v in cumplen_n_personas_mes.items():
            for fecha in fechas.values():
                if fecha[1]==i: # 
                    v+=1
            cumplen_n_personas_mes[c]=v
            i+=1

        print("\n numero de personas que cumplen en cada mes ")
        print ('{:<10}{:>7}'.format('mes','cantidad'))
        for c,v in cumplen_n_personas_mes.items():
            print ('{:<10}{:>7}'.format(c,v))

    elif opcion==3:
        #    punto 3.
        # ¿Qué personas cumplen en cada mes?

        # diccionario que guardara el nombre de las personas que cumplen en cada mes 
        cumplen_meses={"Enero":[], "Febrero":[], "Marzo":[], "Abril":[]
        , "Mayo":[], "Junio":[], "Julio":[], "Agosto":[],
            "Septiembre":[], "Octubre":[], "Noviembre":[], "Diciembre":[]
            }
        i=1
        for m,personas in cumplen_meses.items(): 
            for c,v in fechas.items():
                if v[1]==i:# compatamos el valor del mes de la fecha en cuastion 
                    personas.append(c) #agregamos el nombre de la persona si es que cumple en dicho mes a una lista 
            cumplen_meses[m]=personas # teniendo los nombres de las personas que cumplene en un mes x agregamos dicha lista como valor al diccionario list_mese en su correspondiente mes como valor 
            i+=1

        print("\n Qué personas cumplen en cada mes")
        print ('{:^10}|{:^18}'.format('mes','personas'))
        for c,v in cumplen_meses.items():
            print ('{:^10}|'.format(c),end=" ")
            for i in v:
                print(i,end="  ")
        print("")

    elif opcion==4:
        # punrto 4. 
        # ¿Cuál es la persona con mayor edad?

        mayores_edades={}
        may_edad=(2051,50,32)
        name="persona con mayor edad"

        for c,v in fechas.items():
            if v<=may_edad:
                may_edad=v
                name=c
                mayores_edades[name]=may_edad

        print("\n la o las personas con mayor edad son ")
        print('|{:^10}|{:^10}|'.format('nombre',"edad"))
        for c,v in mayores_edades.items():
            print('|{:^10}|{:^10}|'.format(c,2021-v[0]))
    
    else:
        # punrto 5. 
        # ¿Cuál es la persona con menor edad?
        men_edad=(1051,1,1)
        name="persona con menor edad"

        for c,v in fechas.items():
            if v>=men_edad:
                men_edad=v
                name=c
                    
        
        print("\n la o las personas con menoor edad son ")
        print('|{:^10}|{:^10}|'.format('nombre',"edad"))
        print('|{:^10}|{:^10}|'.format(name,2021-men_edad[0]))
    

    go=int(input("\n desea regresar el menu del programa?\n 1) si \n 2) no \n escriba el numero de su opcion "))