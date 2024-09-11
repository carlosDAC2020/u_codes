import pandas as pd
import re
from unidecode import unidecode
import xlsxwriter

# Lee el archivo CSV
data = pd.read_csv("estudiantes.csv")


# Definir el nombre del archivo de Excel
excel_file = "estudiantes.xlsx"

# Crear un escritor de Excel
workbook = xlsxwriter.Workbook(excel_file)

# Formato para el encabezado
header_format = workbook.add_format({'bold': True, 'align': 'center', 'border': 1, 'bg_color': '#F7F7F7'})


# Crear una hoja de Excel para cada prueba
worksheet = workbook.add_worksheet("estudiantes")

# Crear encabezados
worksheet.write(0, 0, "estudiantes", header_format)
worksheet.write_row(2, 0, ["grado", "nombre", "curso"], header_format)


# Escribir los datos en la hoja de Excel
row = 3
for i, row_data in data.iterrows():
    worksheet.write_row(row, 0, [unidecode(row_data['grado']), unidecode(row_data['nombre']), unidecode(row_data['curso'])])
    row += 1


# Cerrar el archivo de Excel
workbook.close()

print(f"Se ha creado el archivo {excel_file} correctamente.")
