#Tempature Conversion
print('Welcome to this Temperature Conversion Porgram')
name = input('What is your name?').title().strip()
print('Hello '+name+'!')
# Giving Choices
print("Enter 1 if you want to convert from Celsius")
print("Enter 2 if you want to convert from Fahrenheit")
print("Enter 3 if you want to convert from Kelvin")
#Taking input
while True:
    x = input('Enter your choice.. : ')
    y=int(x)
    # Logic to convert when Celsius is Given
    if y==1:
        temp = input('Given temperature in Celsius: ')
        temp_c=int(temp)
        temp_f = (9/5*temp_c)+32
        temp_k = temp_c + 273.15
        temp_f = round(temp_f, 4)
        temp_c = round(temp_c, 4)
        temp_k = round(temp_k, 4)
        print('\nDegrees Celsius:\t\t'+str(temp_c))
        print('Degrees Fahrenheit:\t\t'+str(temp_f))
        print('Degrees Kelvin:\t\t\t'+str(temp_k))
    #Logic to solve when Fahrenheit is Given
    elif y==2:
        temp = input('Given temperature in Fahrenheit: ')
        temp_f = int(temp)
        temp_c = (5/9)*(temp_f-32)
        temp_k = temp_c+273.15
        temp_f = round(temp_f, 4)
        temp_c = round(temp_c, 4)
        temp_k = round(temp_k, 4)
        print('\nDegrees Fehrenheit:\t\t'+str(temp_f))
        print('Degrees Celsius:\t\t'+str(temp_c))
        print('Degrees Kelvin:\t\t\t'+str(temp_k))
    #Logic to solve when Kelvin is Given
    elif y==3:
        temp = input('Given temperature in Kelvin: ')
        temp_k = int(temp)
        temp_c = temp_k-273.15
        temp_f = (9/5*temp_c)+32

        temp_f = round(temp_f, 4)
        temp_c = round(temp_c, 4)
        temp_k = round(temp_k, 4)
        print('\nDegrees Kelvin:\t\t\t' + str(temp_k))
        print('Degrees Celsius:\t\t' + str(temp_c))
        print('Degrees Fahrenheit:\t\t' + str(temp_f))

    else:
        print('Incorrect value')
    for_quit = input('Enter y to quit')
    if for_quit == 'y':
        quit()
    else:
        continue