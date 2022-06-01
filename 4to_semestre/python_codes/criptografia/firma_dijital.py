from Crypto.PublicKey import RSA
from sympy import *

#función para encontrar el máximo común divisor de dos números
def euclid(m, n):
  if n == 0:
    return m
  else:
    r = m % n
    return euclid(n, r)

#función para calcular el inverso multiplicativo
def multiplicative_inverse(a, b):
  r1 = a
  r2 = b
  s1 = int(1)
  s2 = int(0)
  t1 = int(0)
  t2 = int(1)

  while r2 > 0:
    q = r1 // r2
    r = r1 - q * r2
    r1 = r2
    r2 = r
    s = s1 - q * s2
    s1 = s2
    s2 = s
    t = t1 - q * t2
    t1 = t2
    t2 = t
  if t1 < 0:
    t1 = t1 % a
  return (r1, t1)

#ingresamos 2 números primos largos (p y q)
p = 823
q = 953
n = p * q
Pn = (p - 1) * (q - 1)

#generamos nuestras llaves privadas y puublicas
Key = RSA.generate(bits = 1024)
print (f"Public Key: \n n = (hex(Key.n)) \n e = (hex(key.e)) \n")
print (f"Private Key: \n n = (hex(Key.n)) \n d = (hex(key.e)) \n")

#seleccionamos nuestra llave cifrada
e = int(313)

#encontramos el inverso de nuestra llave cifrada en cierto modulo
r, d = multiplicative_inverse(Pn, e)
if r == 1:
  d = int(d)
  print ("Decryption Key: ", d)
else:
  print ("Multiplicative inverse for the given encryption key does not exist. Choose another encryption key")

#el mensaje que se va a mandar a Bob
M = 19070

#La firma que va hacer creada por Alice
s = (M ** d) % n

#Alice manda el mensaje y la firma a Bob, Bob genera un mensaje M1 con la firma, la clave publica de Alice y el producto n
M1 = (s ** e) % n

#comprobamos si el mensaje que mando Alice es el mismo que recibio Bob
if M == M1:
  print ("M = M1, accept the message sent by Alice")
else:
  print ("M not equal to M1, Do not accept the message snet by Alice")