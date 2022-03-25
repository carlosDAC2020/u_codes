import math
# declaramos variables
distancia_objetivo=503
distancia_alcanzada=0 #
gravedad=9.8
angulo=45
velocidad_inicial=0 #




def modalidad1():
  """
   El usuario deberá probar con distintos valores de velocidad hasta sobrepasar la
  distancia de 503 metros con un margen de error del 10%. Para ello, el usuario tendrá un total
  de 6 intentos para lograr el objetivo.
  """
  print("modalidad 1")
  print("probar con distintos valores de velocidad hasta sobrepasar la \n distancia de 503 metros con un margen de error del 10%. Para ello, el usuario tendrá un total\n de 6 intentos para lograr el objetivo.")
  for i in range (6):
    print("\n intento",i+1)
    # pedimos el vakor de la velocidad 
    velocidad_inicial=float(input("ingresa la belocidad del Angry Bird: "))
    
  # procedemoa a encontra la disyancia alcanzada usando la formial porporcionada 
    distancia_alcanzada=((velocidad_inicial**2)/gravedad)*math.sin(2*angulo)

  # margden de error 
    maergen_error=(abs(distancia_alcanzada-distancia_objetivo)/distancia_objetivo)*100
    
    print("la distancia alcanzada fue de",round(distancia_alcanzada,3),"m")
  # evaluamos dependiendo  el resultado de la distancia alcanzada si llega , supera o no el objetivo 
    if distancia_alcanzada > distancia_objetivo and (maergen_error>0 or maergen_error<10 ):
      print(" OBJETIVO ALCANZADO!!")
      print("ha sobrepasado el objetivo por ",round(distancia_alcanzada - distancia_objetivo,3),"metros")
      print(" tiene un margen de error de ",round(maergen_error,3),"%")
      break
    elif distancia_alcanzada > distancia_objetivo:
       print("ha sobrepasado el objetivo por ",distancia_alcanzada - distancia_objetivo,"metros")
       print(" tiene un margen de error de ",round(maergen_error,3),"%")
    else:
      print("no sobrepaso el objetivo \nle faltaron ",round(distancia_objetivo - distancia_alcanzada,3),"metros")
        
#------------------------------------------------------------------------------------------------------------------------

def modalidad2():
  """
  : El usuario deberá probar con distintos valores de velocidad hasta alcanzar la
distancia de 503 metros con un margen de error del 10%. Para ello, el usuario tendrá
indeterminados intentos hasta lograr el objetivo.
  """
  # opcion 1 
  print(" modalidad 2")
  print("con distintos valores de velocidad hasta alcanzar la \n distancia de 503 metros con un margen de error del 10%. Para ello, el usuario tendrá \nindeterminados intentos hasta lograr el objetivo.  \n")
  # pedimos al usuario un numero de intentoa 
  intento="si"
  i=0
  while intento=="si":
    i+=1
    print("intento",i)
    # pedimos el vakor de la velocidad 
    velocidad_inicial=float(input("ingresa la belocidad del Angry Bird: "))
    
  # procedemoa a encontra la disyancia alcanzada usando la formial porporcionada 
    distancia_alcanzada=((velocidad_inicial**2)/gravedad)*math.sin(2*angulo)

    # margden de error 
    maergen_error=(abs(distancia_alcanzada-distancia_objetivo)/distancia_objetivo)*100
    
    print("la distancia alcanzada fue de",round(distancia_alcanzada,3),"m")
  # evaluamos dependiendo  el resultado de la distancia alcanzada si llega , supera o no el objetivo 
    if int(distancia_alcanzada) == distancia_objetivo and (maergen_error>0 or maergen_error<10 ):
        print("felicidades ha alcanzado el objetivo")
        print(" tiene un margen de error de ",round(maergen_error,3),"%")
    elif distancia_alcanzada < distancia_objetivo :
        print("no sobrepaso el objetivo \nle faltaron ",round(distancia_objetivo - distancia_alcanzada,3),"metros")
    else:
        print("ha sobrepasado el objetivo por ",round(distancia_alcanzada - distancia_objetivo,3),"metros")
    
    intento=input("\n desea realizar otro intento (si o no): ")

#-------------------------------------------------------------------------------------------------------------------

def modalidad3():
  """
  El usuario deberá ingresar un rango de velocidades comprendido entre un valor
  inicial y un valor final. El algoritmo tomará cada uno de los valores del rango dependiendo de
  los pasos (incrementos) ingresados por el usuario hasta alcanzar la distancia de 503 metros
  con un margen de error del 5%.
  """
  print(" modalidad 3")
  print(" deberá ingresar un rango de velocidades comprendido entre un valor\n inicial y un valor final. El algoritmo tomará cada uno de los valores del rango dependiendo de \n los pasos (incrementos) ingresados por el usuario hasta alcanzar la distancia de 503 metros \n con un margen de error del 5%.\n")
    
  # pedimos al usuario un valor iniciao y final de un rango de valores q se tomaran como valores para ver si llegan o no al objetivo 
  r1=float(input("ingresa el valor inicial del rango:"))
  r2=float(input("ingresa el valor final del rango:"))
  while r2<r1:
    print("el valor final del rango debe ser mayor que el inicial")
    r2=float(input("ingresa el valor final del rango otra vez :"))
  
  # valor de incremento
  incremento=float(input(" ingrese el icremento a tener en cada evsluacion en el rango de valores: "))
  3

  valores=0 # cantidad total de valores 
  herrados=0 # cantidad total de valores q no coinciden 
  # evaluamos dicho rango de valorwa 
  print("\nevaluando rango..")
  while r1 <= r2:

    print("# valores evaluados :",valores,end="\r")
  # se toma  como valor de vemocidad inicial el primer valoe del rango 
    velocidad_inicial = r1
  
  # encontramos la distancia alcanzada 
    distancia_alcanzada=((velocidad_inicial**2)/gravedad)*math.sin(2*angulo)
    maergen_error=(abs(distancia_alcanzada-distancia_objetivo)/distancia_objetivo)*100
        
      # en el momento en el que el valor de la distancia recorrida swa igual al del objetivo y se cumple el margen de error 
    if int(distancia_alcanzada) == distancia_objetivo and (maergen_error>0 and maergen_error<10):
        v_correcta = velocidad_inicial # se guardara el resultado de la velucidad inicial en uma variavle auxiliar 
        aux_dis_a = distancia_alcanzada # distancia wxacta recorrida hasta el objetivo
        aux_margen_error= maergen_error # margen error de la distancia alcanzada
        
    else:
      herrados=herrados+1 # esta variable contabiliza la cantidad de valores q no llegan al objetivo 
    
    
    valores=valores+1 # esta variable contaviliza la cantidad exacta de valores q se toman 

    r1 +=incremento
      
  print("\n resultados ")    
  if herrados!= valores:
    print("\nla velocidad necesaria para que el angri bird alcance el objetico debe ser de:",round(v_correcta,3),"km/h")
    print("la diatacia que rrecorre el Angry Bird con esta velocidad inicial fue de  ",round(aux_dis_a,3),"m")
    print(" tiene un margen de error de ",round(aux_margen_error,3),"%")
  else:
    print(" en el rango ingresado no se encontro ningun vakor de velocidad correcta ")
  
#------------------------------------------------------------------------------------------------------------------------------------------------------------

def modalidad4():
  """
  El usuario deberá ingresar un rango de velocidades comprendido entre un valor
  inicial y un valor final. El algoritmo tomará cada uno de los valores del rango dependiendo de
  los pasos (incrementos) ingresados por el usuario hasta alcanzar una distancia con un margen
  de error, ambos definidos por el usuario.
  """
  print(" modalidad 4")
  print("deberá ingresar un rango de velocidades comprendido entre un valor\n inicial y un valor final. El algoritmo tomará cada uno de los valores del rango dependiendo de \n los pasos (incrementos) ingresados por el usuario hasta alcanzar la distancia de 503 metros \n con un margen de error tambien ingresado por el usuario \n")
    
  # pedimos al usuario un valor iniciao y final de un rango de valores para la velocidad inicial  
  r1=float(input("ingresa el valor inicial del rango:"))
  r2=float(input("ingresa el valor final del rango:"))
  while r2<r1:
    print("el valor final del rango debe ser mayor que el inicial")
    r2=float(input("ingresa el valor final del rango otra vez :"))
  
  # valor de incremento
  incremento=float(input(" ingrese el icremento a tener en cada evsluacion en el rango de valores: "))
  # rango de margen de error
  r_margen_error=float(input(" ingreso del margen de error a evaluar en cada distancia alcanzada:"))

  valores=0 # cantidad total de valores 
  herrados=0 # cantidad total de valores q no coinciden 
  # evaluamos dicho rango de valorwa 
  print("\nevaluando rango..")
  while r1 <= r2:
  # se toma  como valor de vemocidad inicial el primer valoe del rango 
    velocidad_inicial = r1
  
  # encontramos la distancia alcanzada 
    distancia_alcanzada=((velocidad_inicial**2)/gravedad)*math.sin(2*angulo)
    # margen de error de la distancia obtenida 
    maergen_error=(abs(distancia_alcanzada-distancia_objetivo)/distancia_objetivo)*100
        
      # en el momengto en que la distancia obtenida cumple el margen de error dada por el usuario
    if maergen_error>0 and maergen_error<r_margen_error:
      print(" \n CUMPLE")
      print(" velocidad inicial:",round(velocidad_inicial,3),"km/h")
      print(" distancia alcanzada: ",round(distancia_alcanzada,3),"m")
      print(" margen de error: ",round(maergen_error,3),"%")
        
    else:
      herrados=herrados+1 # esta variable contabiliza la cantidad de valores q no llegan al objetivo 
    
    
    valores=valores+1 # esta variable contaviliza la cantidad exacta de valores q se toman 

    r1 +=incremento
      
  # en caso que ningun valor del rango no cumpla el margen de error 
  if herrados== valores:
    print(" en el rango ingresado no se encontro ningun vakor de velocidad correcta ")
    






pregunta="si"
while pregunta=="si" :

  print("\nDesarrolle un Algoritmo donde se calcule la velocidad de lanzamiento necesaria para que un Angry Bird lanzado desde el piso con una inclinación de 45° sobrepase un objetivo dispuesto a 503 metros de distancia, tomando en cuenta que se rige mediante el cálculo del movimiento parabólico. ")
  
  print("\n que orefieres usar para hayar la velocidad inicial ")
  print(" 1 prueba com 6 valores de velocidad inicial para sobre pazar el objetivo \n")
  print(" 2 prueba con un numero indeterminado de valore de velocidad inicial para alcanzar el objetivo \n ")
  print(" 3 ingreso de un rango de valores de velocvidad inicial para alcanzar el objetivo con un margen de error del 5% \n ")
  print(" 4 ingreso de un rango de valores de velocvidad inicial para alcanzar una distancia que cumpla con un margen de error dado por el usuario \n ")


  # le damoa oa opcion al usuario de como resolver el problema 
  opcion=int(input("ingresa aqui tu opcion deceada:"))
  while opcion<1 or opcion>4 :
    print("\ningreso de valor no valido")
    opcion=int(input("ingresa aqui tu opcion deceada(1 a 4):"))
    3

  if(opcion==1):
    modalidad1()

  elif(opcion==2):
    modalidad2()
  
  elif(opcion==3):
    modalidad3()

  else:
    modalidad4()  
    
  pregunta=input("\nquieres intentarlo otra vez ? si o no :")