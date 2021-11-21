"""usuarios=[]


#file=open("users.txt","r")

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

op=1
while op==1:
    add_user()
    x=int(input("mostrar:"))
    if x==1:
        for i in range(len(usuarios)):
            us= usuarios[i]
            for y,c in us.items():
                print(y,":",c)
            print("")
    op=int(input("seguir: "))
      
    """




import tkinter as tk

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.hi_there = tk.Button(self)
        self.hi_there["text"] = "Hello World\n(click me)"
        self.hi_there["command"] = self.say_hi
        self.hi_there.pack(side="top")

        self.quit = tk.Button(self, text="QUIT", fg="red",
                              command=self.master.destroy)
        self.quit.pack(side="bottom")

    def say_hi(self):
        print("hi there, everyone!")

root = tk.Tk()
app = Application(master=root)
app.mainloop()