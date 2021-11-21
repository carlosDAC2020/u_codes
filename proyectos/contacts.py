usuarios=[]


id_user=0

log=False

# funcion para realizar el loguin del usuario
def login():

  global usuarios # llamammos la lista donde estan guardados los usuarios
  global id_user # variable auxiliar para guardar el indice del usuario a buscar en la lista 
  global log
  print("-"*30)
  while log==False:
    print("{:^20}".format("login"))
    user=input("usuario:")
    password=input("contraseña:")
    i=0
    for usr in usuarios:
        if usr["usuario"]==user and usr["contrasena"]==password:
            id_user=i
            print('-'*30)
            print(" hola",usr["nombre"],usr["apellido"],"buenbenid@ a su registro de contactos")
            print(" contactos")
            if len(usr["contactos"])>0:
                cont=usr["contactos"]
                print("{:^15}{:^15}{:^20}".format("nombre","celular","descripcion"))
                for cts in cont:
                    for cto in cts.values():
                        z=0
                        if z==2:
                            print("{:^20}".format(cto))
                        print("{:^15}".format(cto),end="")
                        z+=1
            log=True
        else:
            print("no tienes contactos guardados")
        return 
  print("datos ingresados herroneos ")
 
 
 # funcuon para agregar un nuevo contacto a la lista de un usuario 
def add_contacts():
  global usuarios
  global id_user
  
  new_contact={}
  
  print("\ndatos del nuevo contacto")
  
  name=input("nombre:")
  new_contact["nombre"]=name

  phone=int(input("celular:"))
  new_contact["celular"]=phone

  described=input("descripcion:")
  new_contact["descripcion"]=described

  i=0
  for us_c in usuarios:
    if i==id_user:
      us_c["contactos"].append(new_contact)
    i+=1
    
    
def delete_contacts():
  
  global usuarios
  global id_user
  
  print("\n contacto a eliminar")
  n_c_delete=input("nombre:")
  
  i=0
  for user in usuarios:
    if i==id_user:
      for cts in user["contactos"]:
        if cts["nombre"]==n_c_delete:
          user["contactos"].remove(cts)
    i+=1

  
  
# funcion para realizar el registro de los usuarios  
def add_user(): 
  print("-"*30)
  user={}
  global usuarios
  print("{:^20}".format("registro"))
  name=input(" •nombre:")
  user["nombre"]=name
  surname=input(" •apellido:")
  user["apellido"]=surname
  print("\ncrea un usuario y contraseña")
  usr=input(" •usuario:")
  user["usuario"]=usr
  pswr=input(" •contrasena")
  user["contrasena"]=pswr
  user["contactos"]=[]
  
  usuarios.append(user)

x="si"
while x=="si" : 
  print("{:^30}".format("resgitro personal de contactos"))
  print("-"*30)
  print("\nguarda tus contactos en nuestto sistema con la mejor seguridad")
  print("     opciones ")
  print(" -> 1 login")
  print(" -> 2 registrate")

  ops=int(input(" escoje una opción:"))

  if ops==1:
    login()
    if log==True:
      print("\n que desea hacer?\n -> 1 agregar contacto \n -> 2 eliminar contacto")
      resp=int(input("digite el nuemro de la opcion deseada:"))
      if resp==1:
        add_contacts()
      else:
        delete_contacts()
     
  elif ops==2:
    add_user()
    
  x=input("\n desea volver al menu si/no:") 
  
print("hasta la próxima!!!")  