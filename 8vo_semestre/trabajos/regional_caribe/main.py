import pandas as pd
import re
from unidecode import unidecode

# Lee el archivo CSV
data = pd.read_csv("datos.csv")

# Definir la lista con los valores dados
pruebas = [
    "Salto con pértiga (Hombres)",
    "100 metros planos (Damas - Hombres)",
    "Salto largo (Damas - Hombres)",
    "400 metros (Damas - Hombres)",
    "Salto alto (Damas - Hombres)",
    "Salto triple (Damas - Hombres)",
    "800 metros (Damas - Hombres)",
    "Salto triple (Damas - Hombres)",
    "200 metros planos (Damas - Hombres)",
    "Relevo 4*100 (Damas - Hombres)"
]

# Obtener los géneros únicos
generos = list(set(data['Genero'].tolist()))

resume ={}
# Iterar sobre las pruebas
for prueba in pruebas:
    # Eliminar caracteres no válidos utilizando una expresión regular
    nombre_archivo = re.sub(r'[\\/*?:"<>|]', '', prueba)
    lista_masculina =[]
    lista_femenina=[]
    # Abre el archivo con el nombre limpio
    with open(f"{nombre_archivo}.txt", "w") as archivo:
        i=0
        print("\n------",prueba)
        archivo.write(f"{prueba}.\n")
        for index, row in data.iterrows():

            lista_pruebas = row["Prueba a inscribir"].split(", ")
            if prueba in lista_pruebas:
                i+=1
                if "Masculina"==row["Genero"]:
                    lista_masculina.append([row['Nombre Completo'],row['Club'],row['Fecha de nacimiento']])
                else:
                    lista_femenina.append([row['Nombre Completo'],row['Club'],row['Fecha de nacimiento']])
                print(i,"-- ",row['Nombre Completo']," --- ",row['Genero'])
    
        archivo.write(f" Hombres\n")
        h=1
        archivo.write("{:^20} {:^20} {:^20} \n".format("nombre","Club","Fecha de nacimiento"))
        for name in lista_masculina:
            archivo.write("{:^20} {:^20} {:^20} \n".format(unidecode(name[0]),unidecode(name[1]),unidecode(name[2])))
            h+=1
        
        archivo.write(f"\n Mujere\n")
        m=1
        archivo.write("{:^20} {:^20} {:^20} \n".format("nombre","Club","Fecha de nacimiento"))
        for name in lista_femenina:
            archivo.write("{:^20} {:^20} {:^20} \n".format(unidecode(name[0]),unidecode(name[1]),unidecode(name[2])))
            m+=1

    resume[prueba]=i

print("\n\nResumen de pruebas")
total=0
for key,value in resume.items():
    print(key,"--",value)
    total+=value
print("\ntotal inscritos:",total)

# salto triple falta 1
