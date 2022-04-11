from random import randint

def valudar_num(num_ev, alt_num):

    if num_ev<alt_num:
        return 3
    elif num_ev>alt_num:
        return 2
    else:
        return 1

go=1
while go==1:
    print(" Adivina un numero del 1 al 100")
    print(" tienes 10 intentos para adivinar ")

    # asignamos el numero aleatorio
    alt_num=randint(1,100)

    print("Empecemos !!!!")
    print(" ya se t ha asiganado un numero del 1 al 100")
    # ejecucion de intentos 
    intento=1

    while intento<=10:
        print("\n intento",intento)
        num=int(input(" ingrese un numero:"))

        ev=valudar_num(num,alt_num)
        if ev==1:
            print(" felicidades has adininado el numero!!")
            break
        elif ev==2:
            print(" el numero ingresado es mayor que el asigando")
            intento+=1
        else:
            print(" el numero ingresado es menor que el asigando")
            intento+=1
            
    print(" el numero asignado fue",alt_num)
    # se le pregunta al usuario si deces volver a jugar 
    print("\n desea volver al menu?")
    print("1-> si\n 2->no")
    go=int(input("ingrese su opcion"))

print("\n gracias por jugar ;)")