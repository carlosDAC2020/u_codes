import pandas as pd
import re
from unidecode import unidecode
import xlsxwriter

# Lee el archivo CSV
data = pd.read_csv("datos.csv")
# Definir la lista con los valores dados
pruebas = [
    "Salto con pértiga",
    "100 metros planos",
    "Salto largo",
    "400 metros",
    "Salto alto",
    "Salto triple",
    "800 metros",
    "200 metros planos",
    "Relevo 4x100"
]

# Definir el nombre del archivo de Excel
excel_file = "datos.xlsx"

# Crear un escritor de Excel
workbook = xlsxwriter.Workbook(excel_file)

# Formato para el encabezado
header_format = workbook.add_format({'bold': True, 'align': 'center', 'border': 1, 'bg_color': '#F7F7F7'})

# Iterar sobre las pruebas
for prueba in pruebas:
    # Crear una hoja de Excel para cada prueba
    worksheet = workbook.add_worksheet(prueba)

    # Crear encabezados
    worksheet.write(0, 0, prueba, header_format)
    worksheet.write(1, 0, "Hombres", header_format)
    worksheet.write(1, 3, "Mujeres", header_format)
    worksheet.write_row(2, 0, ["Nombre", "Club", "Fecha de nacimiento"], header_format)

    # Eliminar caracteres no válidos utilizando una expresión regular
    nombre_archivo = re.sub(r'[\\/*?:"<>|]', '', prueba)

    # Filtrar los datos por la prueba actual
    lista_prueba = data[data['Prueba a inscribir'].str.contains(prueba)]

    # Dividir los datos por género
    hombres = lista_prueba[lista_prueba['Genero'] == 'Masculina']
    mujeres = lista_prueba[lista_prueba['Genero'] == 'Femenina']

    # Escribir los datos en la hoja de Excel
    row = 3
    for i, row_data in hombres.iterrows():
        worksheet.write_row(row, 0, [unidecode(row_data['Nombre Completo']), unidecode(row_data['Club']), unidecode(row_data['Fecha de nacimiento'])])
        row += 1

    row = 3
    for i, row_data in mujeres.iterrows():
        worksheet.write_row(row, 3, [unidecode(row_data['Nombre Completo']), unidecode(row_data['Club']), unidecode(row_data['Fecha de nacimiento'])])
        row += 1

# Cerrar el archivo de Excel
workbook.close()

print(f"Se ha creado el archivo {excel_file} correctamente.")
