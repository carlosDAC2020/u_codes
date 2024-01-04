def convert_decimal(number_str):
    parts = number_str.split('.')
    
    if len(parts) == 2:  # Asegurarse de que hay una parte entera y una parte decimal
        parts[0] = '0'  # Cambiar la parte entera a 0
        
        # Volver a unir las partes para obtener el número modificado
        modified_number = '.'.join(parts)
        return float(modified_number)
    else:
        return number_str  # Retornar tal cual si no hay una parte decimal




fraccionario=float(input("ingresa fraccionario:"))



bites=1
biner =[]
while bites<24:
    r = fraccionario*2
    bit = int(r)
    biner.append(bit)
    print("{:^8}* 2 = {:^8}  -> {:^8}".format(fraccionario, r, bit))

    fraccionario =convert_decimal(str(r))
    
    bites+=1



# Convertir la lista de números a una lista de cadenas con ceros iniciales
lista_cadenas = [str(numero).zfill(1) for numero in biner]

# Unir las cadenas en una sola cadena
cadena = ''.join(lista_cadenas)

print(biner)
print(cadena)

