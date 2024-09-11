import pdfplumber

# Ruta del archivo PDF
pdf_path = "El despertar del Leviatan - the expanse.pdf"
txt_path = "file.txt"

# Abre el archivo PDF
with pdfplumber.open(pdf_path) as pdf:
    # Abre el archivo de salida en modo de escritura
    with open(txt_path, "w", encoding="utf-8") as txt_file:
        # Recorre cada página del PDF
        for page in pdf.pages:
            # Extrae el texto de la página
            text = page.extract_text()
            if text:
                # Escribe el texto en el archivo de salida
                txt_file.write(text)
                txt_file.write("\n")  # Añade un salto de línea entre páginas

print(f"El archivo PDF ha sido convertido a {txt_path}")






import time
import string
import os
import unicodedata

def remove_accents(input_str):
    # Normaliza la cadena a su forma 'NFD' (Canonical Decomposition)
    nfkd_form = unicodedata.normalize('NFD', input_str)
    # Filtra y elimina los caracteres de acento (caracteres con categoría 'Mn')
    return ''.join([c for c in nfkd_form if not unicodedata.combining(c)])

if __name__ == "__main__":
    # Obtén el número de núcleos físicos
    num_cores = os.cpu_count()
    print(f"Número de núcleos (cores): {num_cores}")

    # Ruta del archivo de texto
    file_path = "file.txt"
    # palabra a uscar
    #search_word = input(" ingrese la palabra a buscar:")
    search_word = "nave"
    # Lista para almacenar las palabras
    words_list = []

    # Caracteres adicionales a eliminar (incluye guiones y signos de interrogación/exclamación)
    additional_chars = '—-?¿!¡'
    print(string.punctuation + additional_chars)
    # Crear una tabla de traducción que elimine todos los signos de puntuación y los caracteres adicionales
    translator = str.maketrans('', '', string.punctuation + additional_chars)

    # Abre el archivo en modo de lectura
    with open(file_path, "r", encoding="utf-8") as file:
        # Contador de líneas
        for line in file:
            # Aplicar la traducción para eliminar la puntuación y los guiones
            line = line.translate(translator)
            # Divide la línea en palabras usando el espacio como separador
            words = line.split()
            # Revisa cada palabra antes de eliminar signos de puntuación y tildes
            for word in words:
                # Elimina los signos de puntuación
                cleaned_word = word.translate(translator)
                # Elimina las tildes y convierte a minúsculas
                cleaned_word = remove_accents(cleaned_word).lower()
                words_list.append(cleaned_word)
    
    
    start_time = time.time()
    cant_repeat = 0
    for word in words_list:
        if word == search_word:
            cant_repeat += 1
    end_time = time.time()
    execution_time = end_time - start_time
    
    print(f"La palabra '{search_word}' se repite {cant_repeat} veces")
    print(f"Tiempo de ejecución: {execution_time} segundos")
