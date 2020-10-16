#Python program for Bubble short taking user input

def bubblesort(a, num):                  #fuction for bubbleshort
    for i in range(num -1):
        for j in range(num - i - 1):
            if(a[j] > a[j + 1]):
                 temp = a[j]
                 a[j] = a[j + 1]
                 a[j + 1] = temp

a = []
num = int(input("Please Enter the Total Number of Elements : "))     #for user input number
for i in range(num):
    element = int(input("Please enter the %d Element of List1 : " %i))
    a.append(element)

bubblesort(a, num)
print("The Sorted List in Ascending Order : ", a)
    
      
