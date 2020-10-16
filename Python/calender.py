strtday=int (input("enter the start day (1 to 7 ie 1 for sunday, ...., 7 for Saturday) => "))
numofdays=int (input("enter the no of days in month"))
i=j=0
print("SUN   MON  TUES  WED  THURS  FRI   SAT")
print("_______________________________________")
for i in range(strtday):
    print(end="    ")
i=strtday-1
for j in range(1,numofdays+1):
    if (i>6):
        print('\n')
        i=0
        
    else :
        i+=1
        if(j>9):
            print(str(j),"  ",end=" ")
        else: print(str(j),"   ",end=" ")    
    
    
