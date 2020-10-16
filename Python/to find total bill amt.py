a=input("enter the name of item sold :- ")
r=float(input("enter the rate of commodity"))
q=int(input("enter the quantity :- "))
gst=float(input("enter the GST on the commodity"))
exp=float(input("enter the money soent in production "))
t=r*q
profit=t-exp
tax=t*gst
gt=t+tax

print ("-------------------*BILL*-----------------")
print ("--------------------------------------------")
print ("the total amount of bill is :- ", t)
print ("--------------------------------------------")
print ("the tax on the item is :- ", tax)
print ("--------------------------------------------")
print ("the grand total of the bill is ", gt)
print ("--------------------------------------------")
print("profit on goods is ", profit)

