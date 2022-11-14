# declaramos el diccionario a utilizar 
diccionario={}


# declaramos una lista con los meses del año para apollarnos a la hora de imprimir
meses=("Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio",
        "Agosto","Septiembre","Octubre","Noviembre","Diciembre")


def ingreso_datos():
    # se solicita la cantidad de personas para ingresar sus datos 
    n_per=int(input(" ingrese la cantidad de perdsonas: "))
    # validamos para que el usuario no ingrese numeros negativos
    while n_per<=0:
        print(" no ingresar valores iferiores a 1 !!!")
        n_per=int(input(" ingrese la cantidad de perdsonas nuevamente: "))

    # hacemos el ingreso de los datos de las personas 
    print("\n datos de las personas ")
    for i in range(n_per):
        print("\n perosona ",i+1)
        name = input(" nombre: ")
        print(" fecha de cumpleaños ")
        dia = int(input(" dia: "))
        mes = int(input(" mes: "))
        anio = int(input(" anio: "))
        
        # validamos el ingreso de la fehca de cumpleaños 
        while dia<0 or dia>31 or mes<0 or mes>12 or anio<1935 or anio>2021 or (dia>29 and mes==2):
            print(" fecha invalida \n porv¿favor ingresar nuevamente los datos ")
            dia = int(input(" dia: "))
            mes = int(input(" mes: "))
            anio = int(input(" anio: "))
        
        # añadimos los datos al diccionario 
        diccionario[name]=(dia,mes,anio)

# 1. ¿Qué personas cumplen en un mes en específico? En este punto se debe
#   preguntar al usuario por un mes (int o str) y se debe imprimir la lista de personas que
#   cumplen ese mes.
def punto1():
    print(" Personas que cumplen en un mes en especifico ")
    print(" escoja el mes a evaluar")
    for i in range(1,len(meses)+1):
        print(i," - ",meses[i-1])
    mes=int(input(" ingrese el nuemro correspondiente al mes: "))
    while mes<1 or mes>12:
        print(" ingrese soslo valores entre 1 y 12 !!!")
        mes=int(input(" ingrese nuevamente el nuemro correspondiente al mes: "))

    # declaramos la lsta que ira guardana a las personas que cumplen en el mes selecionado
    per_cumpken=[]

    # hacemos las busqueda en el diccionario
    for name,fch_cump in diccionario.items():
        if fch_cump[1]==mes:
            per_cumpken.append(name)

    # imprimimos los resultados 
    if len(per_cumpken)>0:
        print(" las personas que cumplene en el mes de ",meses[mes-1]," son:")
        for name in per_cumpken:
            print(name)
    else:
        print(" no cumple nadie en ",meses[mes-1])


# 2. ¿Cuántas personas cumplen en cada mes? Ej. En diciembre cumplen 2
#   personas.
def punto2():
    print("\n cantidad de personas que cumplen cada mes ")
    # con un ciclo for vamos evluando en cada mes 
    for i in range(1,13):
        # declaramos una variable comtadora 
        cant=0
        # buscamos en los valores del diccionario que corresponden a las fechas de cumpleaño 
        for v in diccionario.values():
            if i==v[1]:
                cant+=1
        # vamos imprimiendo los resultados por mes 
        print(meses[i-1]," : ",cant)

# 3. ¿Qué personas cumplen en cada mes? Ej. En diciembre cumple ELY, AXA.
def punto3():
    print("\n personas que cumplen cada mes ")
    # con un ciclo for vamos evluando en cada mes 
    for i in range(1,13):
        # declaramos una variable comtadora 
        per=[]
        # buscamos en los valores del diccionario que corresponden a las fechas de cumpleaño 
        for k,v in diccionario.items():
            if i==v[1]:
                per.append(k)
        # vamos imprimiendo los resultados por mes 
        print(meses[i-1])
        if len(per)>0:
            for name in per:
                print(name,end=" ")
        else:
            print(" no cumple nadie ")
        print("\n")


# 4. ¿Cuál es la persona con mayor edad? Pueden ser varias personas
def punto4():
    print("\n Personas con mayor edad")
    per_may_edad=[]
    may_edad=(9999,9999,9999)
    # obtenemos la mayor edad
    for k,v in diccionario.items():
        if v<may_edad: 
            per={}
            may_edad=v
            per[k]=v
    
    # añadimos a la persona con mayor edad a la lista per_may_edad
    per_may_edad.append(per)
    may=tuple(per.values())
    name=tuple(per.keys())
    # validamos si hay personas que cumplan el mismo dia 
    for k,v in diccionario.items():
        if v==may[0]  and k!=name[0]:
            per_may_edad.append({k:v}) # y lo añadimos a la lista per_may_edad

    # imprimimos los resultados 
    if len(per_may_edad)<=1:
        print(" la persona con mayor edad es ")
        for k,v in per.items():
            print(k," con ",2022-v[2]," anios")
    else:
        print(" las personas con mayor edad son ")
        for pers in per_may_edad:
            for k in pers.keys():
                print(" ",k)
        
        fecha=str(v[0]) + "/" + str(v[1]) + "/" + str(v[2])
        edad=2022-v[2]
        print(" las cuales nacieron el ",fecha," y tiene ",edad," anios")


# 5. ¿Cuál es la persona con menor edad? Pueden ser varias personas
def punto5():
    print("\n Personas con menor edad")
    per_men_edad=[]
    men_edad=(0,0,0)
    # obtenemos la menor edad
    for k,v in diccionario.items():
        if v>men_edad: 
            per={}
            men_edad=v
            per[k]=v
    
    # añadimos a la persona con menor edad a la lista per_men_edad
    per_men_edad.append(per)
    men=tuple(per.values())
    name=tuple(per.keys())
    # validamos si hay personas que cumplan el mismo dia 
    for k,v in diccionario.items():
        if v==men[0] and k!=name[0]:
            per_men_edad.append({k:v}) # y lo añadimos a la lista per_men_edad

    # imprimimos los resultados 
    if len(per_men_edad)<=1:
        print(" la persona con men edad es ")
        for k,v in per.items():
            print(k," con ",2022-v[2]," anios")
    else:
        print(" las personas con menor edad son ")
        for pers in per_men_edad:
            for k,v in pers.items():
                print(" ",k)
        
        fecha=str(v[0]) + "/" + str(v[1]) + "/" + str(v[2])
        edad=2022-v[2]
        print(" las cuales nacieron el ",fecha," y  tienen ",edad," anios")
    pass

# funcion principal
def run():
    print(" Gestor de cumpleaños ")
    # ingresamos los datos de las personas 
    ingreso_datos()
    go=1
    # usamos este cilco para hacer que se repita el programa hasta que el usuario quiera
    while go==1:
        print("\n menu")
        print(" 1 - ¿Qué personas cumplen en un mes en específico? ")
        print(" 2 - ¿Cuántas personas cumplen en cada mes? ")
        print(" 3 - ¿Qué personas cumplen en cada mes? ")
        print(" 4 - ¿Cuál es la persona con mayor edad?")
        print(" 5 - ¿Cuál es la persona con menor edad?")
        print(" 6 - ingresar mas datos ")
        print(" 7 - salir del programa ")

        # solicitamos y validamos la opcionn a ejecutar
        op=int(input(" ingrese su opion: "))
        while op<1 or op>7:
            print(" opcion ingresada no valida !!")
            op=int(input(" ingrese su opion nuevamente: "))

        # dependiendo de la opcion escojida de ejecuta la funcion correspondiente 
        if op==1:
            punto1()
        elif op==2:
            punto2()
        elif op==3:
            punto3()
        elif op==4:
            punto4()
        elif op==5:
            punto5()
        elif op==6:
            ingreso_datos()
        else:
            go=0
    
    print("\n fin del programa")

# ejecutamos la funcion principal 
run()