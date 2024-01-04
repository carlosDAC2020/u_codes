entero = int(input("ingresa el numero entero :"))

def validar(num):
    num=str(num)
    parts = num.split('.')
    
    if len(parts) == 2:  # Asegurarse de que hay una parte entera y una parte decimal
        aux = parts[1]
        if int(aux[0]) <5:
            return 0
        else:
            return 1

biner=[]

while True:
    aux = entero/2

    bite = validar(aux)
    biner.append(bite)
    print("{:^8}/ 2 = {:^8}  -> {:^8}".format(entero, aux,bite ))

    entero=aux

    if entero<1:
        break

biner.reverse()

# Convertir la lista de números a una lista de cadenas con ceros iniciales
lista_cadenas = [str(numero).zfill(1) for numero in biner]

# Unir las cadenas en una sola cadena
cadena = ''.join(lista_cadenas)

print(biner)
print(cadena)