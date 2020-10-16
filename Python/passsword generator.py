# ----------------------------------------------- Meer Hamza --------------------------------------------

import random

# Creating arrays
cod=[None]*25
arr=[None]*52

# creating variables 

f=0
z=0
t=0

for i in range(14):
    cod[i]=chr(33+i)

for i in range(14,21):
    cod[i]=chr(58+z)
    z+=1

for i in range(21,25):
    cod[i]=chr(91+t)
    t+=1

for i in range(26):
    arr[i]= chr(65+i)

for i in range (26,52):
    arr[i]=chr(97+f)
    f+=1

print("*****************************************************************")
print("\t\twelcome to password generator")
print("*****************************************************************")

pas=int(input("enter the length of password:\t"))
alph=int(input("enter the number of characters you want in your password:\t"))
num=int(input("enter the number of digits you want in your password:\t"))
passw=[None]*pas

for i in range(alph):
    x=random.randint(0,51)
    passw[i]=arr[x]

for i in range(alph,(alph+num)):
    passw[i]=str(random.randint(0,9))

for i in range((alph+num),(alph+num)+(pas-alph-num)):
    l=random.randint(0,24)
    passw[i]=cod[l]

print("your password is")

for i in range(0, pas):
    print(passw[i],end="")