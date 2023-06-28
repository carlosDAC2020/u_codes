import pandas as pd

# Carga la base de datos "Possum"
data = pd.read_csv("possum.csv") 

# Selecciona las columnas para el análisis de correlación
selected_columns = ['hdlngth', 'skullw', 'totlngth', 'taill', 'footlgth', 'earconch', 'eye', 'chest', 'belly']
selected_data = data[selected_columns]

# Calcula la matriz de correlación
correlation_matrix = selected_data.corr()

# Convierte la matriz de correlación a texto
correlation_text = correlation_matrix.to_string()

# Imprime la matriz de correlación en texto
print("Matriz de correlación:")
print(correlation_text)
