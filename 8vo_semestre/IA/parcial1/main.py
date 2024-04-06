from pyDatalog import pyDatalog

pyDatalog.create_terms('usuario, U, anfitrion, A, fecha, D, M, Y, hora, H, MIN, cnal, C, atiende, cita')

# Hechos -----------------------------------

# anfitriones disponibles
+anfitrion('maria')
+anfitrion('jose')
+anfitrion('ana')

# cita ejemplo 1
+usuario("pedro")
+atiende("maria","pedro")
+fecha(1,2,2024)
+hora(12,34)

# cita ejemplo 2
+usuario("lina")
+atiende("maria","lina")
+fecha(1,2,2024)
+hora(15,56)

# Reglas -----------------------------------

"""
Prolog :
cita(U, A, D, M, Y, H, MIN) :- 
    usuario(U), 
    anfitrion(A), 
    atiende(A, U), 
    fecha(D, M, Y), 
    hora(H, MIN).
"""
cita(U, A, D, M, Y, H, MIN) <= usuario(U) & anfitrion(A) & atiende(A, U) & fecha(D, M, Y) & hora(H, MIN)


while True:
    # ingresamos el ususrio
    u = input("\n Ingrese el nombre del usuario: ")
    +usuario(u)

    print("\n anfitriones disponibles :")
    print(anfitrion(A))
    
    # solicitamos el anfitrion 
    a=input("\nselecciona un anfitrion disponible: ")
   

    #solicitamos la fecha
    date = input("\ningresa la fecha para la cita (D,M,Y):")
    date = date.replace(" ", "")
    date = date.split(",")
    
 
