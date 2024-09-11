import networkx as nx
import matplotlib.pyplot as plt

# Creamos el grafo
G = nx.Graph()

# Definimos los nodos
nodos = ["Cartagena", "Tunja", "Cali", "Florencia", "Ibagué", "Pasto", "Valledupar", "Arauca", "Mocoa", "Medellín"]

# Añadimos los nodos al grafo
G.add_nodes_from(nodos)

# Definimos las aristas con sus respectivas distancias
aristas = [
    ("Cartagena", "Tunja", 897.5), ("Cartagena", "Cali", 1138.3), ("Cartagena", "Florencia", 1440.5),
    ("Cartagena", "Ibagué", 1063.4), ("Cartagena", "Pasto", 1511.7), ("Cartagena", "Valledupar", 497.1),
    ("Cartagena", "Arauca", 897.7), ("Cartagena", "Mocoa", 1524.1), ("Cartagena", "Medellín", 651.9),
    ("Tunja", "Cali", 596.6), ("Tunja", "Florencia", 687.9), ("Tunja", "Ibagué", 339.9), ("Tunja", "Pasto", 963.3),
    ("Tunja", "Valledupar", 382.6), ("Tunja", "Arauca", 721), ("Tunja", "Mocoa", 771.6), ("Tunja", "Medellín", 412.8),
    ("Cali", "Florencia", 428.5), ("Cali", "Ibagué", 252.5), ("Cali", "Pasto", 445.9), ("Cali", "Valledupar", 634.5),
    ("Cali", "Arauca", 880.6), ("Cali", "Mocoa", 530.1), ("Cali", "Medellín", 382.6),
    ("Florencia", "Ibagué", 400.6), ("Florencia", "Pasto", 445.8), ("Florencia", "Valledupar", 889.6),
    ("Florencia", "Arauca", 1266.7), ("Florencia", "Mocoa", 272.5), ("Florencia", "Medellín", 818.3),
    ("Ibagué", "Pasto", 628.7), ("Ibagué", "Valledupar", 1542.1), ("Ibagué", "Arauca", 1348.2),
    ("Ibagué", "Mocoa", 145.6), ("Ibagué", "Medellín", 781.6),
    ("Pasto", "Valledupar", 1508.6), ("Pasto", "Arauca", 1348.2), ("Pasto", "Mocoa", 642.3), ("Pasto", "Medellín", 734.5),
    ("Valledupar", "Arauca", 902.5), ("Valledupar", "Mocoa", 1350.3), ("Valledupar", "Medellín", 167.6),
    ("Arauca", "Mocoa", 641.9), ("Arauca", "Medellín", 803.9),
    ("Mocoa", "Medellín", 837.5)
]

# Añadimos las aristas al grafo
for arista in aristas:
    G.add_edge(arista[0], arista[1], weight=arista[2])


# Dibujamos el grafo
pos = nx.spring_layout(G)  # Posiciones de los nodos
labels = {arista[:2]: arista[2] for arista in aristas}  # Etiquetas de las aristas (distancias)

nx.draw(G, pos, with_labels=True, node_size=100, node_color='skyblue')  # Dibujamos los nodos
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  # Dibujamos las etiquetas de las aristas

plt.show()

# Cambia la disposición de los nodos
pos = nx.circular_layout(G)  # O puedes probar con nx.shell_layout(G)
labels = {arista[:2]: arista[2] for arista in aristas}  # Etiquetas de las aristas (distancias)

# Dibujamos el grafo
nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue')  # Dibujamos los nodos
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)  # Dibujamos las etiquetas de las aristas

plt.show()






"""import networkx as nx
import matplotlib.pyplot as plt

# Creamos un grafo vacío
G = nx.Graph()

# Definimos los nodos
nodos = ["Cartagena", "Tunja", "Cali", "Florencia", "Ibagué", "Pasto", "Valledupar", "Arauca", "Mocoa", "Medellín"]

# Añadimos los nodos al grafo
G.add_nodes_from(nodos)

# Definimos las aristas con sus respectivas distancias
aristas = [
    ("Cartagena", "Tunja", 897.5), 
    ("Cartagena", "Cali", 1138.3), 
    ("Cartagena", "Pasto", 1511.7),
    ("Tunja", "Cali", 596.6), 
    ("Tunja", "Pasto", 963.3),
    ("Cali", "Pasto", 445.9),
    ("Florencia", "Pasto", 445.8),
    ("Ibagué", "Pasto", 628.7),
    ("Valledupar", "Pasto", 1508.6),
    ("Arauca", "Pasto", 1348.2),
    ("Medellín", "Pasto", 734.5)
]

# Añadimos las aristas al grafo
for arista in aristas:
    G.add_edge(arista[0], arista[1], weight=arista[2])

# Dibujamos el grafo
pos = nx.spring_layout(G)
labels = nx.get_edge_attributes(G, 'weight')

nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.show()"""