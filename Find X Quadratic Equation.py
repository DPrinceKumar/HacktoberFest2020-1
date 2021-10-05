# Find X for Quadratic equation
a = eval(input("Insert value for a: "))
b = eval(input("Insert value for b: "))
c = eval(input("Insert value for c: "))

x1 = (-b + ((b**2) - (4*a*c))**0.5)/(2*a)
x2 = (-b - ((b**2) - (4*a*c))**0.5)/(2*a)

print("x1: ", x1)
print("x2: ", x2)
