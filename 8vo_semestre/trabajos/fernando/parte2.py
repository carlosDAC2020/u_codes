import random
import pandas as pd
import networkx as nx
# Particionar el grafo en dos subgrafos
from networkx.algorithms import approximation as approx



# Creamos el grafo
G = nx.Graph()

df = pd.read_csv("distanciab.csv")
df.drop(columns=['Nodo 40'])
print(df)
rutas=[]
distancia=[]

nodos=[]
aristas=[]

for i, row in df.iterrows():
    nodo=row["Nodo"]
    nodos.append(nodo)
    for node in df.drop(columns=['Nodo',"Nodo 40"]):
        rutas.append(f"{nodo} - {node}")
        distancia.append(row[node])
        aristas.append((nodo,node,row[node]))


# Añadimos los nodos al grafo
G.add_nodes_from(nodos)


"""
enunciado 1
"""
# Añadimos las aristas al grafo
for arista in aristas:
    G.add_edge(arista[0], arista[1], weight=arista[2])
cycle = nx.approximation.traveling_salesman_problem(G, cycle=True, weight='weight')
print("Ruta más óptima para el vehiculo segun la distancia:", cycle)


"""
enuciado 2
velocidad promedio del vehiculo
estado del trafico por ruta 
    bajo = velocidad vh 
    moderado = velocidad vh - (velocidad vh)*0.2
    alto = velocidad vh - (velocidad vh)*0.5
"""
velocidad_vehiculo=60 # km/h
def tiempo_ruta(distancia, trafico):
    if trafico == 'bajo':
        velocidad = velocidad_vehiculo
    elif trafico == 'moderado':
        velocidad = velocidad_vehiculo - (velocidad_vehiculo * 0.2)
    elif trafico == 'alto':
        velocidad = velocidad_vehiculo - (velocidad_vehiculo * 0.5)
    return distancia / velocidad

trafico = ['bajo','moderado','alto']
# creamos grafo con base al tiempo q se demora el vehiculo en recorrer cada ruta
G_tienpos_recorrido = nx.Graph()
G_tienpos_recorrido.add_nodes_from(nodos)

for i, row in df.iterrows():
    nodo=row["Nodo"]
    for node in df.drop(columns=['Nodo']):
        traf = random.choice(trafico)
        print(f"{nodo} - {node} \n   {traf} \n :{tiempo_ruta(row[node],traf)}h")
        tiempo=tiempo_ruta(float(row[node]),traf)
        G_tienpos_recorrido.add_edge(nodo, node, weight=tiempo)
        
# ruta mas rapidsa segun el tiempo y trafico
ruta_mas_rapida = nx.approximation.traveling_salesman_problem(G, cycle=True, weight='weight')
print("Ruta más óptima para el vehiculo segun el tiempo y el trafico \n:", ruta_mas_rapida)