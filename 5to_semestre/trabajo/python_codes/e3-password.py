
# 3.4
password="Iloveyou123"
ingre_pass=input(" ingrese una contraseña: ")

while ingre_pass!=password:
    print(" contraseña incorrecta ")
    ingre_pass=input(" ingrese una contraseña nuevamente: ")
    
print(" contraseña correcta ")


# 4.2
password="Iloveyou123"
ingre_pass=input(" ingrese una contraseña: ")

valid=0

intentos=1
while ingre_pass!=password:
    print(" contraseña incorrecta ")
    ingre_pass=input(" ingrese una contraseña nuevamente: ")
    intentos+=1

    if ingre_pass==password:
        valid=1

    if intentos >= 3:
        print(" ya intento 3 veces ")
        break

if valid==1:
    print(" contraseña correcta ")
