"""
SETS:

PLANTAS/1..8/: CAPACIDAD, CFIJO, P; 
CLIENTES/1..6/: DEMANDA;
PXC (PLANTAS, CLIENTES): CT, X;

ENDSETS

DATA:

CAPACIDAD= 1800 1400 1300 1500 2000 1800 1200 1700; 
CFIJO= 12000 11000 12000 11500 15000 14000 10000 14000; 
DEMANDA= 1200 1700 1600 1500 1400 1800;
CT= 10 15 12 13 14 12
    17 14 20 10 15 18
    15 10 11 13 12 16
    13 14 13 15 18 14
    10 12 10 15 12 12
    12 15 17 14 20 11
    11 12 15 10 11 14
    12 11 10 13 16 15:

ENDDATA

MIN = @SUM (PXC (I, J): CT (I, J)*X(I, J)) + @SUM (PLANTAS (I): CFIJO (I)*P(I));

@FOR (PLANTAS (I): @SUM (CLIENTES (J): X(I, J)) <= CAPACIDAD (I) *P(I));

@FOR (CLIENTES (J): @SUM (PLANTAS (I): X(I, J)) >=DEMANDA (J));

@FOR (PLANTAS (I): @BIN (P(I)));
"""

import pulp

# Define los conjuntos
PLANTAS = range(1, 9)
CLIENTES = range(1, 7)

# Define los datos
CAPACIDAD = [1800, 1400, 1300, 1500, 2000, 1800, 1200, 1700]
CFIJO = [12000, 11000, 12000, 11500, 15000, 14000, 10000, 14000]
DEMANDA = [1200, 1700, 1600, 1500, 1400, 1800]
CT = [
    [10, 15, 12, 13, 14, 12],
    [17, 14, 20, 10, 15, 18],
    [15, 10, 11, 13, 12, 16],
    [13, 14, 13, 15, 18, 14],
    [10, 12, 10, 15, 12, 12],
    [12, 15, 17, 14, 20, 11],
    [11, 12, 15, 10, 11, 14],
    [12, 11, 10, 13, 16, 15]
]

# Crea el problema de minimización
problem = pulp.LpProblem("PLM_Problem", pulp.LpMinimize)

# Define las variables de asignación binarias X(i, j)
X = pulp.LpVariable.dicts("X", ((i, j) for i in PLANTAS for j in CLIENTES), cat="Binary")

# Define la función objetivo
beneficio = pulp.lpSum(CT[i - 1][j - 1] * X[i, j] for i in PLANTAS for j in CLIENTES)
costos_fijos = pulp.lpSum(CFIJO[i - 1] * X[i, j] for i in PLANTAS for j in CLIENTES)
problem += beneficio + costos_fijos, "Funcion_Objetivo"

# Define las restricciones
for i in PLANTAS:
    problem += pulp.lpSum(X[i, j] for j in CLIENTES) <= CAPACIDAD[i - 1]

for j in CLIENTES:
    problem += pulp.lpSum(X[i, j] for i in PLANTAS) >= DEMANDA[j - 1]

# Resuelve el problema
problem.solve()

# Muestra los resultados
print("Estado:", pulp.LpStatus[problem.status])
for i in PLANTAS:
    for j in CLIENTES:
        if pulp.value(X[i, j]) > 0:
            print(f"Asignar {pulp.value(X[i, j])} unidades de la planta {i} al cliente {j}")
