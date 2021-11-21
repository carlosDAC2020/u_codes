import random

num=random.randint(1,100)
cont_continue=0
print("el numero escijido es ",num)
while True:
    if num%2==0:
        num=num/2
    else:
        num=num*3+1
    print("-->",num)
    if num==1:
        break