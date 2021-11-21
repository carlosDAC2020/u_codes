
# solicitamos la cantidad de materias que tiene el estudiante en el semestre a evaluar
cant_materias=int(input(" cantidad de materias en su semestre:"))

# declaracion de variables auxiliares 
sum_creditos=0 # cantidad total de creditos del semetre 
sum_n_x_c=0 # suma de la multiplicacion de de la nota final de cada materia con su respectivo numero de creditos 

# ingreso de datos de las materias usando un ciclo while
i=0
while 1<=cant_materias:
	print("\n materia",i+1)
	name_materia=input("materia:")

	nota_final=float(input("nota final:"))
	while nota_final<0 or nota_final>5: # validacion del ingreso de la nota final del estudiante en la materia respectiva 
		print("\n valor ingresado no valido ingrese su nota final nuevamente !!")
		nota_final=float(input("nota final:"))

	n_creditos=int(input("n creditos: "))
	sum_creditos+=n_creditos # vamos sumando la cantidad de crediot totales del estudiante

	credito_x_nota= nota_final*n_creditos # multiplicamos la nota final de la metia en cuestion por su numero de creditos corres pondientes 
	sum_n_x_c+=credito_x_nota # vamos realizando la suma de cada valor que nos arroje la multiplicacion anterior

	i+=1 

# obtenemos el promedio ponderado a partir de la siguiente operacion 
promedio_pon = sum_n_x_c / sum_creditos
# mostramos el promedio final
print("\n RESULTADOS")
print("tu promedio ponderado sera de:", promedio_pon, "\n")
# evaluamos el estado academico del estudiante
if promedio_pon < 3.0:
	print("su rendimienrto como estudisnte es malo ya q perdio el semestre ")

elif promedio_pon >= 3.0 and promedio_pon <= 3.20:
	print("su rendimiento como estudiante es bajo y estaras en observación academica ")

elif promedio_pon >= 3.20 and promedio_pon < 4.0:
	print("tu rendimiento como estudiante es aceptable ")

elif promedio_pon >= 4.0 and promedio_pon < 4.5:
	print("tu rendimiento como estydiante es bueno ")

elif promedio_pon >= 4.5 and promedio_pon <= 5.0:
	print("tu rendimiento como estydiante es exelwnte  ")
