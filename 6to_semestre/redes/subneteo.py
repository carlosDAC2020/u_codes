
import math

# Pedimos la dirección IP, cantidad de subredes y cantidad de hosts al usuario
ip = input("Ingrese la dirección IP (en formato xxx.xxx.xxx.xxx): ")
c = int(input("Ingrese la cantidad de subredes que desea crear: "))
h = int(input("Ingrese la cantidad de hosts que desea tener por subred: "))

# Convertimos la dirección IP en una lista de octetos
octetos = ip.split('.')

# Obtenemos el valor de cada octeto de la dirección IP y los convertimos a enteros
IP = [int(n) for n in octetos]

# Calculamos la cantidad de bits necesarios para representar la cantidad de subredes que se desea crear
bits_subred = math.ceil(math.log2(c))

# Calculamos la cantidad de bits necesarios para representar la cantidad de hosts que se desea tener por subred
bits_host = math.ceil(math.log2(h+2))

# Calculamos la máscara de subred en función de los bits necesarios para representar subredes y hosts
print(32-bits_host+bits_subred+bits_host)
if bits_subred + bits_host <= 32:
    aux = 32-bits_host+bits_subred
    mascara_bin = '1' * aux + "0" * bits_host
    i=1
    for n in mascara_bin:
        if i<9:
            print(n,end="")
        else:
            print(".",end="")
            i=0
        i+=1

    
else:
    print('La cantidad de bits necesarios para la máscara de subred supera los 32 bits de una dirección IP')
    

