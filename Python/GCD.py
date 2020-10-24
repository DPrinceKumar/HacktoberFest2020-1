def gcd(a,b):

    small=0

    gd=0

    if a>b:

        small==b

    else:

        small==a

    for i in range(1, small+1):

        if((a % i == 0) and (b % i == 0)):

            gd=i

    return gd

a=int(input("Enter the first number: "))

b=int(input("Enter second number: "))

t=gcd(a,b)

print("GCD is:",t)
