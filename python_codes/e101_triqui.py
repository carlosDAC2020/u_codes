from random import *

# declaramos la matriz inicial del juego
triqui=[[0 for c in range(3)]for f in range(3)]

print(" juguemos triqui")
for f in range(3):
    print("  ",end="")
    for c in range(3):
        print("{:^3}".format(triqui[f][c]),end="")
    print("")

op=int(input(" desea ver las intrucciones del juego?\n--> 1 si\n--> !=1 no\n dijite su opcion:"))
# instrucciones del juego
if op==1:
    print("{:^15}".format(" intruciones "))
    print(" ingresa la posicion de la fila y de la columna \n para colocar el puntero del jugador")
    print(" estas serian las posiciones")
    print("   ",end="")
    for i in range(3):
        print("{:^3}".format(i+1),end="")
    print()
    for f in range(3):
        print(f+1," ",end="")
        for c in range(3):
            print("{:^3}".format(triqui[f][c]),end="")
        print("")

    print("\n por ejemplo \n si el jugador 1 ingresa\n fila= 2\n columna= 3")
    print("\n o el jugador 2 ingresa\n flia= 3\n columna= 1\n   entonces")
    triqui[1][2]="X"
    triqui[2][0]="O"
    for f in range(3):
        print("  ",end="")
        for c in range(3):
            print("{:^3}".format(triqui[f][c]),end="")
        print("")
    triqui=[[0 for c in range(3)]for f in range(3)]

# inicion del juego
print("\n iniciemos")
turno=1 # variable que maneja los turnos
jugador=0 # variable que mandeja el indice del jugador
lst_coodenadas_ocupadas=[] # lista que ira almacdnando las coordenadas que oran siendo ocupadas por los punteros de los jugadores
while turno<=9:
    # asignacion del jugador segun el turno
    if turno%2==0:
        jugador=2
    else:
        jugador=1

    cords_valido=False
    while cords_valido==False:
        cords=[]
        # ingreso de cordenadas para el puntero
        print(" jugador",jugador,"\n ingrese posiciones de puntero")
        fila=int(input(" fila="))
        cords.append(fila)
        columna=int(input(" columna="))
        cords.append(columna)

        cords=tuple(cords)
        # validacion para que las cordenadas ingresadas no c repitan
        if cords in lst_coodenadas_ocupadas:
            print("\n   ADVERTENCIA\n los valores ingresados ya estan ocupados\n ingresarlos nuevamente")
            cords_valido=False
        else:
            break

    lst_coodenadas_ocupadas.append(cords)

    # asignacion del puntero segun el jugador
    if jugador==1:
        triqui[fila-1][columna-1]="X"
    else:
        triqui[fila-1][columna-1]="O"

    # impresion de la secuencia del juego
    print("\n triqui turno",turno)
    for f in range(3):
        print("  ",end="")
        for c in range(3):
            print("{:^3}".format(triqui[f][c]),end="")
        print("")
    print("")
    if turno>3:
        # evaluamos el ganador
        for i in range(4):
            ganador=0
            if i==0: # evaluamos partiendo de las posiciones verticales
                for f in range(3):
                    x_win=0
                    o_win=0
                    for c in range(3):
                        if triqui[f][c]=="X":
                            x_win+=1
                        if triqui[f][c]=="O":
                            o_win+=1
            elif i==1:# evaluamos a partir de las posiciones horizontales
                for c in range(3):
                    x_win=0
                    o_win=0
                    for f in range(3):
                        if triqui[f][c]=="X":
                            x_win+=1
                        if triqui[f][c]=="O":
                            o_win+=1
            elif i==2: # evaluamos segun la diagonal principal
                x_win=0
                o_win=0
                for x in range(3):
                    if triqui[x][x]=="X":
                        x_win+=1
                    if triqui[x][x]=="O":
                        o_win+=1
            elif i==3:# evaluamos segun la diagonal segundaria
                x_win=0
                o_win=0
                c=2
                for f in range(3):
                    if triqui[f][c]=="X":
                        x_win+=1
                    if triqui[f][c]=="O":
                        o_win+=1
                    c-=1
            # asignacion del ganador segun los resultados de la evaluacion anterior
            if x_win==3:
                ganador=1
            elif o_win==3:
                ganador=2
            if ganador>0:
                print("\n\n FELICIDADES\n el gandor es el jugador",ganador)
                break
    # si antes de culminar los 9 turnos de juego ya existe un gandor se dtiene el juego automaticamente
    if ganador>0:
        break
    turno+=1

if turno==9:
    print("\n no hay ganador en esta partida")
