
# funciones para las operaciones basicas 
def suma(a,b):
    return a+b

def resta(a,b):
    return a-b

def multiplicacion(a,b):
    return a*b

def divicion(a,b):
    return a/b



# ejecucion principal 
go=1
while go==1:
    print(" Iingreso de los numeros aevaluar ")
    num_A=int(input(" ingresa el numero A:"))
    num_B=int(input(" ingresa el numero B:"))
    oper=1
    while oper==1:
        print("\n MENU  DE OPERACIONES ")
        print(" 1-> suma")
        print(" 2-> resta")
        print(" 3-> multiplicacion")
        print(" 4-> divion ")
        
        op=int(input(" ingrese la opcion a realizar:"))
        while op<1 or op>4:
            print(" opcion ingresada no valida ")
            op=int(input(" ingrese la opcion a realizar nuevamente:"))

        if op==1:
            print("\n ",num_A,"+",num_B,"=",suma(num_A,num_B))
        elif op==2:
            print("\n ",num_A,"-",num_B,"=",resta(num_A,num_B))
        elif op==3:
            print("\n ",num_A,"*",num_B,"=",multiplicacion(num_A,num_B))
        else:
            print("\n ",num_A,"/",num_B,"=",divicion(num_A,num_B))
        
        # validamos si el usuario desea hacer otra operacion
        print("\n desea volver al menu de operaciones?")
        print("1-> si\n 1->no")
        oper=int(input("ingrese su opcion"))

    # validamos si el usuario desea hacer otra operacion
    print("\n ingresar otros valores para operar?")
    print("1-> si\n 2->no")
    go=int(input("ingrese su opcion"))

print(" hasta la proximaa!!! ;)")