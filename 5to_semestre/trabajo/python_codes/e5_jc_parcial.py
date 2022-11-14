"""
1) Una empresa tiene la necesidad de una aplicación que le permita recibir los datos
identificativos de sus clientes: Nombre, apellidos, dirección, teléfono, temas de
interés. Luego de almacenarlos debe mostrarlos por una pantalla al área comercial
de la siguiente manera Ejemplo: Juan Pérez, dirección: clle. 74-2, teléfono:
30498484, tema de interés: Aviación
Genere en Python un programa utilizando diccionarios que resuelva esta necesidad

"""
def punto1():
    registro_empleados=[]

    def agregar_empelado(resgitro):
        reg={
            "nombre":"",
            "apellido":"",
            "direccion":"",
            "cel":0,
            "tema interes":""
        }

        print("ingresa los datos de los empleados ")
        reg["nombre"]=input("nombre:")
        reg["apellido"]=input("apellido:")
        reg["direccion"]=input("direccion:")
        reg["cel"]=int(input("celular:"))
        reg["tema interes"]=input("tema de intreres:")

        resgitro.append(reg)

    def mostrar_registro(registro):
        if len(registro)!=0:
            i=1
            for empl in registro:
                print(" empleado ",i)
                for k,v in empl.items():
                    print(k,": ",v)
        else:
            print(" el registro esta vacio")
    while True:
        print("\n\n registro de empleados ")
        print(" 1 mostrar empleados ")
        print(" 2 añadir al registro empleados ")
        op=int(input("ingrese su opcion:"))
        while op<1 or op>2:
            print(" valor ingresado no valido! ")
            op=int(input("ingrese su opcion nuevamnete:"))

        if op==1:
            mostrar_registro(registro_empleados)
        else:
            agregar_empelado(registro_empleados)

        go=int(input(" salir del programa (1=si 2=n0):"))

        if go==1:
            break
punto1()

"""
2) La tienda de Don Miguel necesita un programa para gestionar el precio de sus
productos y con base a esto generar la factura de lo vendido. Teniendo en cuenta lo
anterior, resuelva con los diccionarios de Python La necesidad de Don Miguel. Es
decir, el programa debe solicitar mínimo 5 productos con su precio. Luego, registrar
una venta y calcular el valor a pagar con base en los precios registrados. Si el
producto solicitado no existe en el inventario, enviar una alerta.
"""
def punto2():
    productos={
        "bolsa de arroz":2500,
        "verdura":2000,
        "gaseosa":2600,
        "dulce":500,
        "fruta":1000,
    }
    print("productos")
    for p in productos.keys():
        print("#",p)

    print("\n pedimos los productos")
    valor_a_pagar=0
    for i in range(5):
        print("producto ",i+1)
        name=input("nombre:")

        if name in productos.keys():
            valor_a_pagar+=productos[name]
        else:
            print(" el producto no se encuentra en la base de datos ")

    print("\n el valor de compra a pagar es de :",valor_a_pagar,"$")

punto2()
"""
3)Realizar una función que guarde en un diccionario los créditos de los cursos de una
carrera {'Progración': 3, 'Cálculo': 4, 'Taller de escritura': 2} y luego muestre por
pantalla los créditos de cada curso en el formato “Curso” tiene “Créditos” créditos,
donde “Cursos” es cada uno de los cursos de la carrera, y “Créditos” son sus créditos.
Finalmente imprime el total de créditos de todos los cursos.
"""
def punto3():
    materias={
        "programacion":3,
        "calculo":4,
        "quimica":3,
        "fisica":4,
        "algebra":4
    }
    

    print("materias")
    for k,v in materias.items():
        print("la curso de ",k," tiene ",v," creditos")
punto3()
