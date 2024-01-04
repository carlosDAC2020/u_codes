def float_to_binary(f):
    # Convierte el número de punto flotante a su representación binaria
    binary_representation = format(struct.unpack('!I', struct.pack('!f', f))[0], '032b')
    return binary_representation

import struct

# Ejemplo de uso
numero_flotante = 5.9006
binario = float_to_binary(numero_flotante)
print(binario)
