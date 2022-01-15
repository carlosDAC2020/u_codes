import numpy as np
"""
# declaramos una lista de estatura en cm
heights = [189, 170, 189, 163, 183, 171, 185, 168, 173, 183, 173, 173, 175, 178, 183, 193, 178, 173, 174, 183, 183, 180, 168, 180, 170, 178, 182, 180, 183, 178, 182, 188, 175, 179, 183, 193, 182, 183, 177, 185, 188, 188, 182, 185, 191]
# comvertimos la lista anterior en un array de tip numpy
heights_arr = np.array(heights)
# usamos la funcion .size para obtener el tamaño del array
print(heights_arr.size)
# la funcion ,shape retorna las dimenciones de la matriz que le pasemos 
print(heights_arr.shape)

"""
#--------------------------------------------------

# recopilacion de edades y estatura de presidentes
ages = [57, 61, 57, 57, 58, 57, 61, 54, 68, 51, 49, 64, 50, 48, 65, 52, 56, 46, 54, 49, 51, 47, 55, 55, 54, 42, 51, 56, 55, 51, 54, 51, 60, 62, 43, 55, 56, 61, 52, 69, 64, 46, 54, 47, 70]
heights = [189, 170, 189, 163, 183, 171, 185, 168, 173, 183, 173, 173, 175, 178, 183, 193, 178, 173, 174, 183, 183, 180, 168, 180, 170, 178, 182, 180, 183, 178, 182, 188, 175, 179, 183, 193, 182, 183, 177, 185, 188, 188, 182, 185, 191]

# unimos las listas anteriores en una matriz
edades_y_alturas = heights + ages 
# convertimos la lista anterior en un array numpy
heights_and_ages_arr = np.array(edades_y_alturas)
# imprimimos las dimenciones de la matriz anteriro
print(heights_and_ages_arr.shape)
# comvertimos la lista anteriro en una matriz d 2 por 45
# donde la primera fila seran las alturas y la segunda las edades
print(heights_and_ages_arr.reshape((2,45)))

# indexacion
# podemos acceder a los elementos de los array np usando los indices normales de python
heights_arr = np.array(heights)
# asi indexamos un array unidimencional
print(heights_arr[2])
# asi indexamos un  array bidimencional
print(heights_and_ages_arr[1,2])

# para re asignar valores a los arrays usamos la siguiente sintaxis
heights_and_ages_arr[0.3]=165 # reasignamos un nuevo valor a ese elemnento de la matriz
