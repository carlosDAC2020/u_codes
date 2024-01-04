"""
Escriba un programa que lea siete coordenadas de datos, 
empezando por los valores de x, luego los de y. 
El programa debe mostrar a la salida los siguientes 
estadísticos en el orden mostrado:

- Desviación estándar con 4 cifras significativas
- Error estándar del estimado con 4 cifras significativas
- Coeficiente de determinación con 3 cifras significativas
- Coeficiente de correlación con 3 cifras significativas

case=prueba1
input=
1
2
3
4
5
6
7
0.5
2.5
2.0
4.0
3.5
6.0
5.5

output=
1.9457
0.7735
0.868
0.932


"""
from math import sqrt


# declaramos funciones para obtener los estadisticos solicitados 

# Función para calcular la media
def media(lista):
    return sum(lista) / len(lista)

# Desviación estándar con 4 cifras significativas
def desv_std(var):
    med_var = media(var)
    sum_var=0
    for v in var:
        sum_var+=(v-med_var)**2

    return round(sqrt(sum_var/(len(var)-1)), 4)


# error estándar del estimado con 4 cifras significativas
def error_std_stm(x, y):
    n = len(x)
    
    # Calcular los promedios de x e y
    promediox = sum(x) / n
    promedioy = sum(y) / n
    
    # Calcular la covarianza
    covarianzaxy = sum((x[i] - promediox) * (y[i] - promedioy) for i in range(n)) / n
    
    # Calcular la varianza de x
    varianzax = sum((x[i] - promediox) ** 2 for i in range(n)) / n
    
    a = covarianzaxy / varianzax
    b = promedioy - a * promediox
    
    # Calcular los valores estimados de y
    yestimado = [a * xi + b for xi in x]
    
    # Calcular el error estándar
    errorestandar = ((sum((y[i] - yestimado[i]) ** 2 for i in range(n)) / (n - 2)) ** 0.5) 
    
    
    return round(errorestandar, 4)

# coeficiente de determinación con 3 cifras significativas
def coef_det(x, y):
    media_x = media(x)
    media_y = media(y)
    n = len(x)
    suma_xy = sum([(x[i] - media_x) * (y[i] - media_y) for i in range(n)])
    suma_x2 = sum([(x[i] - media_x)**2 for i in range(n)])
    suma_y2 = sum([(y[i] - media_y)**2 for i in range(n)])
    r_cuadrado = (suma_xy**2) / (suma_x2 * suma_y2)
    return round(r_cuadrado, 3)

# coeficiente de correlación con 3 cifras significativas
def coef_corl(x, y):
    r_cuadrado = coef_det(x, y)
    r = r_cuadrado**0.5
    return round(r, 3)


# funcion principal en la que ejecuta el programa 
def run():
    x=[1,2,3,4,5,6,7]
    y=[0.5,2.5,2.0,4.0,3.5,6.0,5.5]
    # declaramos las listas con las variables correspondientes 
    #x=[]
    #y=[]
    """
    #print(" ingresa los valores de x:")
    for i in range(7):
        aux=float(input())
        x.append(aux)

    #print(" ingresa los valores de y:")
    for i in range(7):
        aux=float(input())
        y.append(aux)
    """
    
        
    # imprimimos los valores de X, Y
    #print("variables")
    #print(" X = ",x)
    #print(" Y = ",y)

    # imprimimos los estadisticos solicitados usando las funciones correspondientes
    #print("Estadisticos")
    #print(" Desviación estándar: ", desv_std(y))
    #print(" Error estándar del estimado: ",error_std_stm(x,y))
    #print(" Coeficiente de determinación: ",coef_det(x,y))
    #print(" Coeficiente de correlación ",coef_corl(x,y))
    print(desv_std(y))
    print(error_std_stm(x,y))
    print(coef_det(x,y))
    print(coef_corl(x,y))
# llamamos la funcion principal 
run()


def aux():
    x=[1,2,3,4,5,6,7]
    y=[0.5,2.5,2.0,4.0,3.5,6.0,5.5]

    x=[]
    y=[]
    for i in range(7):
        lugar_x=float(input())
        x.append(lugar_x)
    
    for i in range(7):
        lugar_y=float(input())
        y.append(lugar_y)
    
    promediox=sum(x)/7
    promedioy=sum(y)/7

    covarianzaxy = sum((x[i] - promediox)*(y[i] - promedioy) for i in range(7))/7 
    varianzax=sum((x[i] - promediox)**2 for i in range(7))/7
    varianzay=sum((y[i] - promedioy)**2 for i in range(7))/7
    varianzaymuestral=sum((y[i] - promedioy)**2 for i in range(7))/(7-1)
    a= covarianzaxy/varianzax
    b= promedioy-a*promediox

    yestimado = [a * x[i] + b for i in range(7)]

    errorestandar=((sum((y[i]-yestimado[i])*2 for i in range(7))/(7-2))*0.5)+0.0001


    desviacionestandarx=(varianzax**0.5)
    desviacionestandary=(varianzay**0.5)
    desviacionestandarymuestral=(varianzaymuestral**0.5)



    coeficientededeterminacion=(covarianzaxy**2)/(varianzax*varianzay)
    coeficientedecorrelacion=(covarianzaxy)/(desviacionestandarx*desviacionestandary)

    print(round(desviacionestandarymuestral,4))
    print(round(errorestandar,4))
    print(round(coeficientededeterminacion,3))
    print(round(coeficientedecorrelacion,3))

#aux()