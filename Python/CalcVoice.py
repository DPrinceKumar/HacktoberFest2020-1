import time
import functools
import operator
import math
import pyttsx3

print("Date:",time.strftime("20%y/%m/%d"))      #printing date and time
print("Time:",time.strftime("%H:%M"))
ct = int(time.strftime('%H'))
print()

aawaj=input("Which one you prefer, Me as a BOY or Me as a GIRL ?: ")

if aawaj=='GIRL':
    def say(text):                                  #defining speech function
        engine = pyttsx3.init()
        voices=engine.getProperty('voices')
        engine.setProperty('voice',voices[1].id)
        engine.say(text)
        engine.runAndWait()

if aawaj=='BOY':
    def say(text):
        engine = pyttsx3.init()
        voices = engine.getProperty('voices')
        engine.setProperty('voice', voices[0].id)
        engine.say(text)
        engine.runAndWait()

say("Thank you for choosing me !")

say("Hello ! What is your name ?")              #knowing u
if ct< 12:                                      #greetings according to time
    say("Good Morning" + input("Hello ! What's your name ? "))
elif 12 <= ct< 17:
    say("Good Afternoon" + input("Hello ! What's your name ? "))
else:
    say("Good Evening" + input("Hello ! What's your name ? "))
say(" WELCOME TO  SUBIN'S  CALCULATOR")

print()

def main():           #defining whole program so that u can re-run it without exiting

    print("1.Addition")
    print("2.Subtraction")                      #listing operations
    print("3.Multiplication")
    print("4.Division")
    print("5.Solve Quadratic Equation")
    print("6.Find The Square Root")
    print("7.Find The Square")
    print("8.Find The Cube Root")
    print("9.Find The Cube")
    print("10.Find The Percentage")
    print("11.Calculate The Logarithm")

    print()

    while True:                                  #handling the exceptions
        try:
            say("Which Operation do you want to perform ? ")
            a=int(input("Which Operation you wanna perform ? : "))
        except ValueError:
            say("Please Enter a Number.")
            print()
            continue

        else:                                   #informing the user about the entries
            if a == 1:
                say("You have selected addition")
            if a == 2:
                say("you have selected subtraction")
            if a == 3:
                say("You have selected multiplication")
            if a == 4:
                say("You have selected Division")
            if a == 5:
                say("You have choosen to solve a quadratic equation")
            if a == 6:
                say("You have choosen to find the square root of a number")
            if a == 7:
                say("You have choosen to find the square of a number")
            if a == 8:
                say("you have choosen to find the cube root of a number")
            if a == 9:
                say("You have choosen to find the cube of a number")
            if a == 10:
                say("You have choosen to calcuate the percentage")
            if a == 11:
                say("You have choosen to calculate the log")

            if a > 11 or a <= 0:                       #being funny, for a wrong input...hahaha
                say("An Eye Hospital may be right choice for you. Thank You !")
                print("An Eye Hospital may be right choice for you. Thank You !")
                 
                print()
                
                say('Do You Want To Re-Run The Calculator ?')          #Wanna Re-Run ??
                again=input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a == 5:                            #solving a quadratic equation
                print("The quadratic equation is : ax2 + bx + c = 0")
                say("Enter   a ")
                q = int(input("Enter a: "))
                say("Enter   b ")
                w = int(input("Enter b: "))
                say("Enter   c ")
                t = int(input("Enter c: "))
                y = (w ** 2) - (4 * q * t)
                s1 = (-w - (y ** (1 / 2))) / (2 * q)
                s2 = (-w + (y ** (1 / 2))) / (2 * q)
                print("The solutions are", s1, "and", s2)
                say("The solutions are:  "+str(s1)+"and  "+str(s2))
                say("Successfully Calculated ! ") 
                print("MADE BY SUBIN")

                print()
                        
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a == 6:
                say("Enter The Number : ")                 #finding square root
                s = int(input("Enter The Number : "))
                print("The Square Root of", s, "is : ", math.sqrt(s))
                say("The square root of"+str(s)+"is:  "+str(math.sqrt(s)))
                say("Successfully Calculated ! ")
                print("MADE BY SUBIN")

                print()
                        
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a == 7:                                #finding square
                say("Enter The Number : ")
                s = int(input("Enter The Number : "))
                print("The Sqaure of ", s, "is : ", math.pow(s, 2))
                say("The Sqaure of "+str(s)+ "is:  "+str(math.pow(s, 2)))
                say("Successfully Calculated ! ")
                print("MADE BY SUBIN")

                print()
                        
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a == 8:                            #finding cuberoot
                say("Enter The Number : ")
                s = int(input("Enter The Number : "))
                print("The Cube Root of ", s, "is : ", s ** (1 / 3))
                say("The Cube Root of "+str(s)+"is:  "+str(s ** (1 / 3)))
                say("Successfully Calculated ! ")
                print("MADE BY SUBIN")

                print()
                
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a == 9:
                say("Enter The Number : ")                  #finding cube
                s = int(input("Enter The Number : "))
                print("The Cube of ", s, "is : ", s ** 3)
                say("The Cube of "+str(s)+"is:  "+ str(s ** 3))
                say("Successfully Calculated ! ")
                print("MADE BY SUBIN")

                print()
                
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a == 10:                               #calculating percentage
                say("Enter The Principle Number: ")
                s = int(input("Enter The Principle Number: "))
                say("Enter The Percentage Rate: ")
                x = int(input("Enter The Percentage Rate: "))
                print(x, "% of", s, "is", (s * x) / 100)
                say(str(x)+ "percentage of"+str(s)+"is:  "+str((s * x) / 100))
                say("Successfully Calculated ! ")
                print("MADE BY SUBIN")

                print()
                
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)

            elif a==11:                             #calculating log
                say("Enter The Number: ")
                s=int(input("Enter The Number: "))
                say("Enter The base: ")
                x=input("Enter The base: ")
                if x=='e':
                    print("The Logarithm of", s, "with base 'e' is", math.log(s))
                    say("The Logarithm of"+str(s)+"with base 'e' is:  "+str(math.log(s)))
                else:
                    print("The Logarithm of",s,"with base",x,"is",math.log(s,int(x)))
                    say("The Logarithm of"+str(s)+"with base"+str(x)+"is:  "+str(math.log(s,int(x))))
                say("Successfully Calculated ! ")
                print("MADE BY SUBIN")

                print()
                
                say('Do You Want To Re-Run The Calculator ?')
                again = input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                if again == 'y':
                    main()
                else:
                    say("Thanks For Using My Calculator !")
                    exit(0)


            list = []           #defining a list to perform addition and multiplicatiion

            while True:         #handling exceptions
                try:            #asking how many nos.will be used for the calculation
                    say("How many numbers are you going to use for the calculation ?")
                    b = int(input("How many numbers u gonna use for calculation ? : "))

                except ValueError:
                    say("Please Enter a Number.")
                    print()
                    continue

                else:

                    if b <= 1:               #being rude, for a wrong input..hahaha
                        print("What are you doing here ? Go to 3rd Standard to study Maths well...")
                        print("How can I perform calculation with",b,"numbers. ")
                        say("Please Enter a valid number.")

                        print()
                        
                        say('Do You Want To Re-Run The Calculator ?')
                        again=input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                        if again == 'y':
                            main()
                        else:
                            say("Thanks For Using My Calculator !")
                            exit(0)

                    elif a == 2:                #performing subtraction
                        say("Please Enter The Numbers")
                        c=int(input("Enter The Number: "))
                        for i in range(b-1):
                            d=int(input("Enter The Number: "))
                            c=c-d
                        print("The Result is :",c)
                        say("The Result is :  "+str(c))

                    elif a == 4:                #performing division
                        say("Please Enter The Numbers")
                        c=int(input("Enter The Number: "))
                        for i in range(b-1):
                            d=int(input("Enter The Number: "))
                            c=c/d
                        print("The Result is :",c)
                        say("The Result is :  "+str(c))

                    elif b >= 1:            #appending the entries to the defined list
                        say("Please Enter The Numbers")
                        for x in range(b):
                            list.append(int(input("Enter The Number: ")))

                    else:
                        say("An Eye Hospital may be right choice for you. Thank You !")
                        print("An Eye Hospital may be right choice for you. Thank You !")

                        print()

                    if a == 1:                  #performing addition
                        print("The Sum is :", sum(list))
                        say("The Sum is :  "+str(sum(list)))

                    elif a == 3:                   #performing multiplication
                        q = functools.reduce(operator.mul, list)
                        print("The Product is:", q)
                        say("The Product is:  "+str(q))

                    say("Successfully Calculated ! ")
                    print("MADE BY SUBIN")              #credit to me...hahahaha

                    print()
                    print()

                    say("Do You Want To ReRun The Calculator ? ")
                    again=input('Do You Want To Re-Run The Calculator ? (y/n):  ')
                    if again == 'y':
                        main()
                    else:
                        say("Thanks For Using My Calculator !")   #Thank u
                        exit(0)

main()                          #calling the function to initialize the programme
