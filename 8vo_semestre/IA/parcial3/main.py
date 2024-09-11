import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Cargar los datos
train_data = pd.read_csv('train_data.csv')
test_data = pd.read_csv('test_data.csv')


# Contar la cantidad de comentarios por tipo de opinión
opinion_counts = train_data['Opinión'].value_counts()
# Crear el gráfico
plt.figure(figsize=(10, 6))
sns.barplot(x=opinion_counts.index, y=opinion_counts.values, palette='viridis')
plt.title('Cantidad de comentarios por tipo de opinión')
plt.xlabel('Tipo de Opinión')
plt.ylabel('Cantidad de Comentarios')
plt.show()