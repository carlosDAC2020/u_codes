from random import randint,choice

# listas de los datos a recojer 
names_animales=[]
sexo=[]
sx=["Hembra","Macho"]
peso_inicial=[]
peso_final=[]

# variables a encontar
    # para las hembras 
cant_hembras=0
sum_pi_hembras=0
prom_pi_hembras=0
    # para los machos 
cant_machos=0
sum_pi_machos=0
prom_pi_machos=0
    # a todos los animales 
sum_pi_general=0
prom_genral_pi=0


# ingreso aleatorio de los datos de los animales 
for i in range(25):
    # nombre
    names_animales.append("Animal "+str(i+1))
    # sexo
    sexo.append(choice(sx))
    # peso inicla 
    peso_inicial.append(randint(195,215))
    # peso final
    peso_final.append(randint(650,750))

    # obtenemos los promedios de pesos iniciales y cantidades
    # de hembras y machos a demas del promedio genral 
    if sexo[i]=="Hembra":
        cant_hembras+=1
        sum_pi_hembras+=peso_inicial[i]
    else:
        cant_machos+=1
        sum_pi_machos+=peso_inicial[i]

    sum_pi_general+=peso_inicial[i]


# obtenemos promedios 
prom_pi_hembras = sum_pi_hembras/cant_hembras
prom_pi_machos = sum_pi_machos/cant_machos
prom_genral_pi = sum_pi_general/25

# imprimimos los datos de los animales 
print("Tabla de resultados ")
print("-"*55)
print ('|{:^10}|{:^10}|{:^15}|{:^15}|'.format('Nombre','sexo','peso inicial','peso final'))
print("-"*55)
for i in range(25):
        print ('|{:^10}|{:^10}|{:^15}|{:^15}|'.format(names_animales[i], sexo[i], peso_inicial[i], peso_final[i]))
print("-"*55)

print("-"*42)
print ('|{:^10}|{:^10}|{:^18}|'.format('sexo','cantidad','prom peso inicla'))
print("-"*42)
print ('|{:^10}|{:^10}|{:^18}|'.format('Hembras',cant_hembras, round(prom_pi_hembras,4)))
print ('|{:^10}|{:^10}|{:^18}|'.format('Machos',cant_machos, round(prom_pi_machos,4)))
print("-"*42)

print("\n Promedio genral de pesos iniciales:",prom_genral_pi)

# animal con mayor y menor porcentaje de crecimiento
porct_may_crecimiento=0
indice_animal_may_prt=0

porct_men_crecimiento=200
indice_animal_men_prt=0

for i in range(25):
    aux_porcent = ((peso_final[i]-peso_inicial[i])/peso_final[i])*100

    if aux_porcent>porct_may_crecimiento:
        porct_may_crecimiento=aux_porcent
        indice_animal_may_prt=i

    if aux_porcent<porct_men_crecimiento:
        porct_men_crecimiento=aux_porcent
        indice_animal_men_prt=i

print("\nn animal con mayor porcentaje de crecimiento")
print("-"*62)
print ('|{:^12}|{:^15}|{:^15}|{:^15}|'.format('Nombre','peso inicial','peso final',"p crecimiento"))
print("-"*62)
print ('|{:^12}|{:^15}|{:^15}|{:^15}|'.format(names_animales[indice_animal_may_prt], peso_inicial[indice_animal_may_prt], peso_final[indice_animal_may_prt],round(porct_may_crecimiento,4)))
print("-"*62)

print("\n animal con menor porcentaje de crecimiento")
print("-"*62)
print ('|{:^12}|{:^15}|{:^15}|{:^15}|'.format('Nombre','peso inicial','peso final',"p crecimiento"))
print("-"*62)
print ('|{:^12}|{:^15}|{:^15}|{:^15}|'.format(names_animales[indice_animal_men_prt], peso_inicial[indice_animal_men_prt], peso_final[indice_animal_men_prt],round(porct_men_crecimiento,4)))
print("-"*62)


# obtenemos la efectividad del metodo 
cant_sup_700kg=0
for i in range(25):
    if peso_final[i]>=700:
        cant_sup_700kg+=1
eficiencia=(cant_sup_700kg/25)*100
print(" la eficiencia del metodo fue del.",round(eficiencia,3),"%")
