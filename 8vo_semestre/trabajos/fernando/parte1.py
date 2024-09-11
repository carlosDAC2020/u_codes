import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt
# Particionar el grafo en dos subgrafos
from networkx.algorithms import approximation as approx

# Creamos el grafo
G = nx.Graph()

df = pd.read_csv("distancia1.csv")

rutas=[]
distancia=[]

nodos=[]
aristas=[]

for i, row in df.iterrows():
    nodo=row["Nodo"]
    nodos.append(nodo)
    for node in df.drop(columns=['Nodo']):
        rutas.append(f"{nodo} - {node}")
        distancia.append(row[node])
        aristas.append((nodo,node,row[node]))


# Añadimos los nodos al grafo
G.add_nodes_from(nodos)

# Añadimos las aristas al grafo
for arista in aristas:
    G.add_edge(arista[0], arista[1], weight=arista[2])


# Dibujamos el grafo
pos = nx.spring_layout(G)  # Posiciones de los nodos
labels = {arista[:2]: arista[2] for arista in aristas}  # Etiquetas de las aristas (distancias)

nx.draw(G, pos, with_labels=False, node_size=100, node_color='skyblue')  # Dibujamos los nodos
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  # Dibujamos las etiquetas de las aristas

plt.show()

#ruta mas optima en el q se recorran todos los nodos por una sola persona 
# Encontrar la ruta más óptima para una persona
cycle = nx.approximation.traveling_salesman_problem(G, cycle=True, weight='weight')
print("Ruta más óptima para una persona:", cycle)

#ruta mas optima en el q se recorran todos los nodos por 2 persona sin repetir  
# Particionar el grafo en dos subgrafos utilizando Kernighan-Lin
partition = nx.algorithms.community.kernighan_lin_bisection(G, weight='weight')

# Obtener los subgrafos
subgraph1 = G.subgraph(partition[0])
subgraph2 = G.subgraph(partition[1])

# Encontrar la ruta más óptima para cada subgrafo
cycle1 = nx.approximation.traveling_salesman_problem(subgraph1, cycle=True, weight='weight')
cycle2 = nx.approximation.traveling_salesman_problem(subgraph2, cycle=True, weight='weight')

print("Ruta más óptima para la primera persona:", cycle1)
print("Ruta más óptima para la segunda persona:", cycle2)

# Dibujar solo las rutas más óptimas
pos1 = nx.spring_layout(subgraph1)
pos2 = nx.spring_layout(subgraph2)


# Grafo para una persona
optimal_edges = [(cycle[i], cycle[i+1]) for i in range(len(cycle)-1)] + [(cycle[-1], cycle[0])]
optimal_labels = {(u, v): f"{G[u][v]['weight']}" for u, v in optimal_edges}

plt.figure(figsize=(10, 5))

plt.subplot(131)
nx.draw(G, pos, nodelist=cycle, edgelist=optimal_edges, with_labels=False, node_size=100, node_color='skyblue')
nx.draw_networkx_edge_labels(G, pos, edge_labels=optimal_labels)
plt.title("Ruta óptima para una persona")

# Grafo para la primera persona en la partición
optimal_edges1 = [(cycle1[i], cycle1[i+1]) for i in range(len(cycle1)-1)] + [(cycle1[-1], cycle1[0])]
optimal_labels1 = {(u, v): f"{subgraph1[u][v]['weight']}" for u, v in optimal_edges1}

plt.subplot(132)
nx.draw(subgraph1, pos1, nodelist=cycle1, edgelist=optimal_edges1, with_labels=False, node_size=100, node_color='skyblue')
nx.draw_networkx_edge_labels(subgraph1, pos1, edge_labels=optimal_labels1)
plt.title("Ruta óptima para la primera persona")

# Grafo para la segunda persona en la partición
optimal_edges2 = [(cycle2[i], cycle2[i+1]) for i in range(len(cycle2)-1)] + [(cycle2[-1], cycle2[0])]
optimal_labels2 = {(u, v): f"{subgraph2[u][v]['weight']}" for u, v in optimal_edges2}

plt.subplot(133)
nx.draw(subgraph2, pos2, nodelist=cycle2, edgelist=optimal_edges2, with_labels=False, node_size=100, node_color='skyblue')
nx.draw_networkx_edge_labels(subgraph2, pos2, edge_labels=optimal_labels2)
plt.title("Ruta óptima para la segunda persona")

plt.tight_layout()
plt.show()