import math
# declaramos variables
distancia_objetivo=503
distancia_alcanzada=0 #
gravedad=9.8
angulo=45
velocidad_inicial=0 #

pregunta="si"

while pregunta=="si" :

  print("\nDesarrolle un Algoritmo donde se calcule la velocidad de lanzamiento necesaria para que un Angry Bird lanzado desde el piso con una inclinación de 45° sobrepase un objetivo dispuesto a 503 metros de distancia, tomando en cuenta que se rige mediante el cálculo del movimiento parabólico. ")
  
  print("\n que orefieres usar para hayar la velocidad inicial \n 1 prueba com distintos valores n veces \n 2 usa un rango de valores \n ")
  
  # le damoa oa opcion al usuario de como resolver el problema 
  opcion=int(input("ingresa aqui tu opcion deceada:"))
  while opcion!=1 and opcion!=2 :
    print("\ningreso de valor no valido")
    opcion=int(input("ingresa aqui tu opcion deceada (1 o 2:"))
    
    # opcion 1 
  if opcion==1:
    print("\n ingresa vafios valores de velocidad inicial para probarlos \n")
    # pedimos al usuario un numero de intentoa 
    intentos= int(input("ingresar el numero de inyentos a realizar: "))
    
    for i in range (1,intentos+1):
      print("intento",i)
      # pedimos el vakor de la velocidad 
      velocidad_inicial=float(input("ingresa la belocidad del Angry Bird: "))
      
  # procedemoa a encontra la disyancia alcanzada usando la formial porporcionada 
      distancia_alcanzada=((velocidad_inicial**2)/gravedad)*math.sin(2*angulo)
      
      print("la distancia alcanzada fue de",distancia_alcanzada,"m")
  # evaluamos dependiendo  el resultado de la distancia alcanzada si llega , supera o no el objetivo 
      if distancia_alcanzada == distancia_objetivo:
          print("felicidades ha alcanzado el objetivo")
      elif distancia_alcanzada < distancia_objetivo :
          print("no sobrepaso el objetivo \nle faltaron ",distancia_objetivo - distancia_alcanzada,"metros")
      else:
          print("ha sobrepasado el objetivo por ",distancia_alcanzada - distancia_objetivo,"metros")

  # opcion 2 		        
  else:
    print("\n evaluemos un rango de valoresn para probar el angulo")
    
    # pedimos al usuario un valor iniciao y final de un rango de valores q se tomaran como valores para ver si llegan o no al objetivo 
    r1=float(input("ingresa el valor inicial del rango:"))
    r2=float(input("ingresa el valor final del rango:"))
    while r2<r1:
      print("el valor final del rango debe ser mayor que el inicial")
      r2=float(input("ingresa el valor final del rango otra vez :"))
      
    valores=0 # cantidad total de valores 
    herrados=0 # cantidad total de valores q no coinciden 
    # evaluamos dicho rango de valorwa 
    while r1 <= r2 :
    # se toma  como valor de vemocidad inicial el primer valoe del rango 
        velocidad_inicial = r1
    
    # encontramos la distancia alcanzada 
        distancia_alcanzada=((velocidad_inicial**2)/gravedad)*math.sin(2*angulo)
        print("\ncon velocidad inicial de:",velocidad_inicial)
        print("distancia alcanzada:",distancia_alcanzada,"m")
          
        
        # en el momento en el que el valor de la distancia recorrida swa igual al del objetivo se ejecutara eate condicional if 
        if int(distancia_alcanzada) == distancia_objetivo :
            v_correcta = velocidad_inicial # se guardara el resultado de la velucidad inicial en uma variavle auxiliar 
            aux_dis_a = distancia_alcanzada # distancia wxacta recorrida hasta el objetivo
            
        else:
          herrados=herrados+1 # esta variable contabiliza la cantidad de valores q no llegan al objetivo 
        
        
        valores=valores+1 # esta variable contaviliza la cantidad exacta de valores q se toman 
        r1 = r1+0.1
    """esto es muy importante:
    	la variable del valor inicial del rango se le iram sumando 0.1 para ir cambiando e ir probanso sus valorea hasta llehar el valor final del ramgo 
    """
        
    if herrados!= valores:
      print("\nla velocidad necesaria para que el angri bird alcance el objetico debe ser de:",v_correcta,"km/h")
      print("la diatacia que rrecorre el Angry Bird con esta velocidad inicial fue de  ",aux_dis_a,"m")
    
    else:
      print(" en el rango ingresado no se encontro ningun vakor de velocidad correcta ")
    
    
  pregunta=input("\nquieres intentarlo otra vez ? si o no :")