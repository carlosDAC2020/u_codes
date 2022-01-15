# EJEMPLO3
# Campeonato de futbol: La llave es la tupla con los nombres de los participantes
# y los valores tuplas con los resultados de los partidos
resultados = {
('Honduras', 'Chile'): (0, 1),
('Espana', 'Suiza'): (0, 1),
('Suiza', 'Chile'): (0, 1),
('Espana', 'Honduras'): (3, 0),
('Suiza', 'Honduras'): (0, 0),
('Espana', 'Chile'): (2, 1),
}
for i in resultados.items():
  print(i)
#    Actividades propuestas
# 1. Lista de los paises que participaron
# 2. Calcular los puntos así: El equipo que gana un partido recibe tres puntos
#    y el que pierde, cero. En caso de empate, ambos equipos reciben un punto.
# 3. Calcular la diferencia de goles. La diferencia de goles de un equipo 
#    es el total de goles que anoto un equipo menos el total de goles
#    que recibio.


# solucion 

# punto 1
paises_participantes=set() # conjuntos donde guardaremos los equipos participantes
llaves=resultados.keys()# por mesio del metodo keys obtenemos las llaves 
list_llaves=list(llaves)# las llaves obtenidas las guardamos en una lista 
for i in range(len(list_llaves)):
  aux=list(list_llaves[i])
  for x in range(len(aux)):
    paises_participantes.add(aux[x])
  
print("\n los paises participantes fueron:\n",paises_participantes) 

# punto 2
puntos={"Chile":[],"Honduras":[],"Suiza":[],"Espana":[]
}

for llave in resultados.keys():
  if resultados[llave][0]>resultados[llave][1]:
    puntos[llave[0]].append(3)
    puntos[llave[1]].append(0)
  
  elif resultados[llave][0]<resultados[llave][1]:
    puntos[llave[0]].append(0)
    puntos[llave[1]].append(3)
  else:
    puntos[llave[0]].append(1)
    puntos[llave[1]].append(1)
 
print("\n\n lo snpuntos obtenidos por cada equipp fueron de ")  
can_p_x_equipo=[]
for punt in puntos.values():
  aux_sum=0
  for i in range(len(punt)):
    aux_sum+=punt[i]
  
  can_p_x_equipo.append(aux_sum)   
 
p_punts=0 
print("{:^14} {:^14}".format("equipo","puntos totales")) 
for eq in puntos.keys():
  print("{:^14} {:^14}".format(eq,can_p_x_equipo[p_punts])) 
  p_punts+=1


# punto 3
goles_anotados={"Chile":[],"Honduras":[],"Suiza":[],"Espana":[]}
goles_recibidos={"Chile":[],"Honduras":[],"Suiza":[],"Espana":[]}
for llave in resultados.keys():
  # agregamos lo goles anotados a cada equipo 
  goles_anotados[llave[0]].append(resultados[llave][0])
  goles_anotados[llave[1]].append(resultados[llave][1])
  # agregamos los goles recibidos a cada equipo
  goles_recibidos[llave[0]].append(resultados[llave][1])
  goles_recibidos[llave[1]].append(resultados[llave][0])
  
can_goles_anotados_equipos=[]
for gol_ant in goles_anotados.values():
  aux_sum=0
  for i in range(len(gol_ant)):
    aux_sum+=gol_ant[i]
  
  can_goles_anotados_equipos.append(aux_sum)   
  
can_goles_recibidos_equipos=[] 
for gol_res in goles_recibidos.values():
  aux_sum=0
  for i in range(len(gol_res)):
    aux_sum+=gol_res[i]
  
  can_goles_recibidos_equipos.append(aux_sum)   

dif_goles=[]
for i in range(len(can_goles_recibidos_equipos)):
  df_g=can_goles_anotados_equipos[i] - can_goles_recibidos_equipos[i]
  dif_goles.append(df_g)
print("\n los goles anotado y recibidos a demas de la diferencia de goles de cada equipo es la siguiente") 

print("{:^14} {:^14} {:^14} {:^14}".format("equipo","goles anotados","goles recibidos","dif goles")) 
p_gol=0
for gl in goles_anotados.keys():
  print("{:^14} {:^14} {:^14} {:^14}".format(gl,can_goles_anotados_equipos[p_gol],can_goles_recibidos_equipos[p_gol],dif_goles[p_gol]))
  p_gol+=1