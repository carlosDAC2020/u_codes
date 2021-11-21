
# numeros decimales a binarios
def decimal_binario():
    numero_decimal = 29 # este es el número que queremos convertir a binario

    modulos = [] # la lista para guardar los módulos

    while numero_decimal != 0: # mientras el número de entrada sea diferente de cero
        # paso 1: dividimos entre 2
        modulo = numero_decimal % 2
        cociente = numero_decimal // 2
        modulos.append(modulo) # guardamos el módulo calculado
        numero_decimal = cociente # el cociente pasa a ser el número de entrada

    print(modulos)

# octal hexadecimal