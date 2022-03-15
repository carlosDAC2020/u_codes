print(" datos obtenidos de la formula de posicion con respecto al tiempo")
print("-"*23)
print("|{:^10}|{:^10}|".format("tiempo","posicion"))
print("-"*23)
for t in range(11):
    Y=2*(t**2)-15*t+40
    print("{:^10}{:^10}".format(t,Y))
print("-"*23)



print("\n datos obtenidos de la formual de la velocidad con respecto al tiempo")
print("-"*23)
print("|{:^10}|{:^10}|".format("tiempo","velocidad"))
print("-"*23)
for t in range(11):
    v=4*t-15
    print("|{:^10}|{:^10}|".format(t,v))
print("-"*23)
