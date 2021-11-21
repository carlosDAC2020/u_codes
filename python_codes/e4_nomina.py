print(" nomina de un trabajador ")

print("\n DATOS DEL TRABAJADOR")
name=input("nombre: ")
last_name=input(" apellido: ")
salario_hora=float(input(" salario por hora: "))
horas_ordinarias=int(input(" horas ordinarias trabajadas: "))
horas_extras=int(input(" horas extras trabajadas: "))

# calculo del salario neto y retencion en la fuente
pago_horas=salario_hora * horas_ordinarias 
valor_estra=(salario_hora * 0.4) + salario_hora # esto se le sumara al salrio por horas extra
pago_horas_extra= valor_estra * horas_extras 
salario_neto= pago_horas + pago_horas_extra 
retencion_fuente= salario_neto * 0.1 
salario_total= salario_neto - retencion_fuente 

print("\n")
print("-"*33)
print("{:^30}".format("datos del empleado"))
print("-"*33)
print("|{:^20}|{:^10}|".format("nombre",name))
print("|{:^20}|{:^10}|".format("apellido",last_name))
print("|{:^20}|{:^10}|".format("salario neto",salario_neto))
print("|{:^20}|{:^10}|".format("rent en la fuenet",retencion_fuente))
print("|{:^20}|{:^10}|".format("salario a pagar",salario_total))
print("-"*33)