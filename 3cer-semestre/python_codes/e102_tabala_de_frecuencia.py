from random import choice

marcas=["G","O", "O", "P", "B","Ca", "O", "O", "Ch", "P", "O", "B", "G", "B", "P", "P", "Ch", "O", "G", "O", "G", "Ca", "O", "G", "Ca", "B", "G", "B", "Ca", "Ch", "P", "B", "O", "O", "G", "B", "B", "G", "O", "B", "B", "Ca", "Ch", "Ch", "Ch", "Ca", "O", "G", "Ca", "O", "B", "G", "G", "Ch", "P", "P", "Ca", "O", "B", "Ca"]

n_muestras=len(marcas)

mts=set()
for i in range(len(marcas)):
    elm=choice(marcas)
    mts.add(elm)


mts=list(marcas)

dic_T=dict()
for i in mts:
    dic_T[i]=0

Fa=[]
for mta in dic_T.keys():
    for mt in marcas:
        if mta==mt:
            dic_T[mta]+=1
    
for cont in dic_T.values():
    Fa.append(cont)

Fp=[]
Fr=[]


for x in Fa:
    aux= x/n_muestras
    Fr.append(round(aux,2))
    aux2=aux*100
    Fp.append(round(aux2,2))
i=0
print("-"*45)
print("|{:^10}|{:^10}|{:^10}|{:^10}|".format("marcas","Fa","Fr","Fp"))
print("-"*45)
for x,y in dic_T.items():
    print("|{:^10}|{:^10}|{:^10}|{:^10}|".format(x,y,Fr[i],Fp[i]))
    i+=1
    if i==6:
        total=[sum(Fa),sum(Fr),sum(Fp)]
        print("|{:^10}|{:^10}|{:^10}|{:^10}|".format("total",total[0],total[1],total[2]))
print("-"*45)