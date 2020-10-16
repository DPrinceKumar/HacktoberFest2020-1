import sys
h=m=h1=m1=h2=m2=0;

ch = input("c for car \n t fro truck or bus \n s for scooter \nPlease Enter the code for the vehicle : ");

tot=0

if (ch=='c'):
    print(format ('*','*<20'),"YOU HAVE PARKED A CAR",format ('*','*<20'))
    c=int(input("CHOOSE THE FORMAT FOR ENTERING THE TIME \n1 for 24 hour format \n2 for 12 hr format \n Enter the choice => "))
    if (c==1):
        print(format ('*','*<20'),"ENTRY TIMINGS DETAILS",format ('*','*<20'))
        h1=int(input("ENTER THE HOUR "))

        if (h1>23):
            print("you have entered a wrong time")
            sys.exit()
            
        m1=int(input("ENTER THE MINUTE "))
        if (m1>60):
            print("you have entered a wrong time")
            sys.exit()

        print(format ('*','8<20'),"exit TIMINGS DETAILS ",format ('*','*<20'))
        h2=int(input("ENTER THE HOUR "))

        if (h2>23):
            print("you have entered a wrong time")
            sys.exit()
            
        m2=int(input("ENTER THE MINUTE "))

        if (m2>60):
            print("you have entered a wrong time")
            sys.exit()

        print("Entry time is : ",h1,":",m1)
        print("exit time is  : ",h2,":",m2)
        
       
        if (m2<m1):
            m1=60-m1
            m2=m2-0
            m=m1+m2
            
        else :
            m=m2-m1
        if(m2-m1<60 and h2-h1==1):
            h=0

        else :
            h=h2-h1

            print("The timings for which parking was used is : ", h,":",m)

        if(h<3):
            tot=20*h
        elif (h>3):
            tot=30*h
        print(format ("\n \n ",'*','*<20'),"TOTAL BILL",format ('*','*<20'))
        print("The total amt is : ", tot)

    # 12 hr format

    if (c==2):
        print(format ('*','*<20'),"ENETRY TIMINGS DETAILS",format ('*','*<20'))
        f1=input("ENTER THE FORMAT i.e. a for am and p for pm ")
        h1=int(input("ENTER THE HOUR "))

        if (h1>12):
            print("you have entered a wrong time")
            sys.exit()
            
        m1=int(input("ENTER THE MINUTE "))

        if (m1>60):
            print("you have entered a wrong time")
            sys.sys.exit()()
        
        print(format ('*','*<20'),"exit TIMINGS DETAILS ",format ('*','*<20'))
        f2=input("ENTER THE FORMAT i.e. a for am and p for pm ")
        h2=int(input("ENTER THE HOUR "))
        if (h2>12):
            print("you have entered a wrong time")
            sys.exit()
        
        m2=int(input("ENTER THE MINUTE "))

        if (m2>60):
            print("you have entered a wrong time")
            sys.exit()
        if (m2<m1):
            m1=60-m1
            m2=m2-0
            m=m1+m2
            
        else :
            m=m1-m2
        if(m2-m1<60 and h2-h1==1):
            h=0
        elif (f1==f2):
            h=h2-h1

        elif (f1!=f2):
            h1=12-h1
            h2=h2-0
            h=h1+h2
        
        print("The timings for which parking was used is : ", h,":",m)

        if(h<3):
            tot=10*h
        elif (h>3):
            tot=20*h
        print("\n \n ",format ('*','*<20'),"TOTAL BILL",format ('*','*<20'))
        print("The total amt is : ", tot)

if (ch=='t'):
    print("you have parked a bus / a truck")

    c=int(input("CHOOSE THE FORMAT FOR ENTERING THE TIME \n1 for 24 hour format \n2 for 12 hr format \n Enter the choice => "))
    if (c==1):
        print(format ('*','*<20'),"ENETRY TIMINGS DETAILS",format ('*','*<20'))
        h1=int(input("ENTER THE HOUR "))

        if (h1>12):
            print("you have entered a wrong time")
            sys.exit()
        
        m1=int(input("ENTER THE MINUTE "))
        if (m1>60):
            print("you have entered a wrong time")
            sys.exit()
        
        print(format ('*','8<20'),"exit TIMINGS DETAILS ",format ('*','*<20'))
        h2=int(input("ENTER THE HOUR "))

        if (h2>12):
            print("you have entered a wrong time")
            sys.exit()
        
        m2=int(input("ENTER THE MINUTE "))

        if (m2>60):
            print("you ahve entered a wrong time")
            sys.exit()
        
        print("Entry time is : ",h1,":",m1)
        print("sys.exit() time is  : ",h2,":",m2)
        
       
        if (m2<m1):
            m1=60-m1
            m2=m2-0
            m=m1+m2
            
        else :
            m=m2-m1
        if(m2-m1<60 and h2-h1==0):
            h=0

        else :
            h=h2-h1

            print("The timings for which parking was used is : ", h,":",m)

        if(h<3):
            tot=20*h
        elif (h>3):
            tot=30*h
        print(format ("\n \n ",'*','*<20'),"TOTAL BILL",format ('*','*<20'))
        print("The total amt is : ", tot)

    # 12 hr format

    if (c==2):
        print(format ('*','*<20'),"ENETRY TIMINGS DETAILS",format ('*','*<20'))
        f1=input("ENTER THE FORMAT i.e. a for am and p for pm ")
        h1=int(input("ENTER THE HOUR "))
        if (h1>12):
            print("you have entered a wrong time")
            sys.exit()
        m1=int(input("ENTER THE MINUTE "))
        if (m1>60):
            print("you have entered a wrong time")
            sys.exit()
        
        print(format ('*','*<20'),"exit TIMINGS DETAILS ",format ('*','*<20'))
        f2=input("ENTER THE FORMAT i.e. a for am and p for pm ")
        h2=int(input("ENTER THE HOUR "))
        if (h2>12):
            print("you have entered a wrong time")
            sys.exit()
            
        m2=int(input("ENTER THE MINUTE "))
        if (m1>60):
            print("you have entered a wrong time")
            sys.exit()
        
        if (m2<m1):
            m1=60-m1
            m2=m2-0
            m=m1+m2
            
        else :
            m=m1-m2
        if(m2-m1<60 and h2-h1==1):
            h=0
        elif (f1==f2):
            h=h2-h1

        elif (f1!=f2):
            h1=12-h1
            h2=h2-0
            h=h1+h2
        
        print("The timings for which parking was used is : ", h,":",m)

        if(h<3):
            tot=20*h
        elif (h>3):
            tot=30*h
        print("\n \n ",format ('*','*<20'),"TOTAL BILL",format ('*','*<20'))
        print("The total amt is : ", tot)


if (ch=='s'):
    print("you have parked a scooter")

    c=int(input("CHOOSE THE FORMAT FOR ENTERING THE TIME \n1 for 24 hour format \n2 for 12 hr format \n Enter the choice => "))
    if (c==1):
        print(format ('*','*<20'),"ENETRY TIMINGS DETAILS",format ('*','*<20'))
        h1=int(input("ENTER THE HOUR "))
        if (h1>23):
            print("you have entered a wrong time")
            sys.exit()
        m1=int(input("ENTER THE MINUTE "))
        if (m1>60):
            print("you have entered a wrong time")
            sys.exit()
        
        print(format ('*','8<20'),"exit TIMINGS DETAILS ",format ('*','*<20'))
        h2=int(input("ENTER THE HOUR "))
        if (h2>23):
            print("you have entered a wrong time")
            sys.exit()
        
        m2=int(input("ENTER THE MINUTE "))
        if (m2>60):
            print("you have entered a wrong time")
            sys.exit()
        
        print("Entry time is : ",h1,":",m1)
        print("sys.exit() time is  : ",h2,":",m2)
        
       
        if (m2<m1):
            m1=60-m1
            m2=m2-0
            m=m1+m2
            
        else :
            m=m2-m1
        if(m2-m1<60 and h2-h1==0):
            h=0

        else :
            h=h2-h1

            print("The timings for which parking was used is : ", h,":",m)

        if(h<3):
            tot=20*h
        elif (h>3):
            tot=30*h
        print(format ("\n \n ",'*','*<20'),"TOTAL BILL",format ('*','*<20'))
        print("The total amt is : ", tot)

    # 12 hr format

    if (c==2):
        print(format ('*','*<20'),"ENETRY TIMINGS DETAILS",format ('*','*<20'))
        f1=input("ENTER THE FORMAT i.e. a for am and p for pm ")
        h1=int(input("ENTER THE HOUR "))
        if (h1>12):
            print("you have entered a wrong time")
            sys.exit()
            
        m1=int(input("ENTER THE MINUTE "))
        if (m1>60):
            print("you have entered a wrong time")
            sys.exit()
        
        print(format ('*','*<20'),"exit TIMINGS DETAILS ",format ('*','*<20'))
        f2=input("ENTER THE FORMAT i.e. a for am and p for pm ")
        h2=int(input("ENTER THE HOUR "))
        if (h2>12):
            print("you have entered a wrong time")
            sys.exit()
        m2=int(input("ENTER THE MINUTE "))
        if (m2>60):
            print("you have entered a wrong time")
            sys.exit()
        
        if (m2<m1):
            m1=60-m1
            m2=m2-0
            m=m1+m2
            
        else :
            m=m1-m2
        if(m2-m1<60 and h2-h1==1):
            h=0
        elif (f1==f2):
            h=h2-h1

        elif (f1!=f2):
            h1=12-h1
            h2=h2-0
            h=h1+h2
        
        print("The timings for which parking was used is : ", h,":",m)

        if(h<3):
            tot=5*h
        elif (h>3):
            tot=10*h
        print("\n \n ",format ('*','*<20'),"TOTAL BILL",format ('*','*<20'))
        print("The total amt is : ", tot)

        
        
        


