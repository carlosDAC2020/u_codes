valor="00001011001000000000110"

acum=0
i=2
for bite in valor:
    acum+=int(bite)*(1/i)
    print("{:^8}* 1/{:^1} = {:^8}  ".format(bite, i , round(int(bite)*(1/i),4)))

    i*=2

print(acum)