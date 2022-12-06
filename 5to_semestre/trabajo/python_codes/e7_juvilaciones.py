def listaJubilacion():
    n = int(input("¿Cuantos son? "))
    while n < 1:
        n = int(input("¿Cuantos son? "))
    edades = []
    tiempos = []


    for i in range(n):
        edad = float(input("Ingrese edad: "))
        edades.append(edad)
        tiempo = float(input("Ingrese tiempo: "))
        tiempos.append(tiempo)

        print("\n ")


    cuentaviejos = 0
    cuentajoven = 0
    cuentaadultos = 0
    jubilacionAdulta = 0.0
    jubilacionEdad = 0.0
    jubilacionJoven = 0.0


    for i in range(n):
        if edades[i]>=60:
            if tiempos[i]<=25:
                cuentaviejos+=1
            else:
                cuentaadultos+=1
        elif edades[i]<60 and tiempos[i]>=25:
            cuentajoven+=1
            
            

    jubilacionEdad = (cuentaviejos*100)/n
    jubilacionJoven = (cuentajoven*100)/n
    jubilacionAdulta = (cuentaadultos*100)/n

    print("porcentaje jubilación edad: ",jubilacionEdad)
    print("porcentaje jubilación joven: ",jubilacionJoven)
    print("porcentaje jubilación adulta: ",jubilacionAdulta)

listaJubilacion()