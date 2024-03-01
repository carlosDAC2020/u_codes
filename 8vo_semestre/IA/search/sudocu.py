# Resolver sudocu usando emetodod de  Backtracking

# librerias a utilizar 
import random

dificultades = {
    'Fácil': lambda: random.randint(30, 39),
    'Medio': lambda: random.randint(40, 49),
    'Difícil': lambda: random.randint(50, 59),
    'Experto': lambda: random.randint(60, 71) 
}
# generar sudocu 
sudoku = [["x" for _ in range(9)] for _ in range(9)]
    
casillas=[]
def generar_sudoku(dificultad):

    # espacios a resolver 
    for _ in range(dificultad):
        fila = random.randint(0, 8)
        columna = random.randint(0, 8)
        auxcasilla =[fila,columna]
        while auxcasilla in casillas:
            fila = random.randint(0, 8)
            columna = random.randint(0, 8)
            auxcasilla =[fila,columna]
        casillas.append(auxcasilla)
        sudoku[fila][columna] = 0

    #  rellenado de espacios
    def asignar_numero(f,c):
        num=random.choice(nums)
        # se valida q no se repita en la fila  
        print(num,' ',sudoku[f])
        if (num in sudoku[f]) :
            nums.remove(num)
            asignar_numero(f,c)
        # se valida q no se repita en la columna
        print(num,' ',[sudoku[i][c] for i in range(9)])
        if num in [sudoku[i][c] for i in range(9)]:
            nums.remove(num)
            asignar_numero(f,c)
        # se valida q no se repita en el cuadrante 
        if val_cuadrante(f,c,num):
            nums.remove(num)
            asignar_numero(f,c)

        sudoku[f][c] = num

    for f in range(9):
        for c in range(9):
            nums=[i for i in range(1,10)]
            # se valida q no este en la lista de casillas vacias
            if [f,c] in casillas:
                continue
            # asignamos valores del 1 al 9 haciendo susu repctivas validaciones 
            asignar_numero(f,c)
        print('\n actualizacion ')
        for sud in sudoku:
                print(sud)
        print()

    
    

# validaciones 
def val_cuadrante(f,c,num):
    pass

                
    

# Solicitar al usuario que elija la dificultad
print("Elige la dificultad para el sudoku:")
for i, dificultad in enumerate(dificultades.keys(), 1):
    print(f"{i}. {dificultad}")

opcion = int(input("Ingrese el número correspondiente a la dificultad: "))
dificultad_elegida = list(dificultades.keys())[opcion - 1]
# Obtener el número de espacios vacíos para la dificultad elegida
dificultad = dificultades[dificultad_elegida]()

generar_sudoku(dificultad)

for sud in sudoku:
    print(sud)