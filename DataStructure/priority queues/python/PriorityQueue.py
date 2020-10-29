def swap(array,i,j): #this simply swaps the values
    array[i],array[j]=array[j],array[i]


'''HeapifyMax function, our root node is at index i. We will first assume that 
the value at index 'i' is the largest. Then we will find index of left and right child.
Then we will check if left and right child exist or not.Now, we will compare our value 
at index i with left and right child. If either of two children have greater value 
then "largest" will store the index of greater value and will swap
the values. if the largest is equal to index i then no swapping. This will be a recursive
funtion so that value gets to its correct position. MAKES PARENT MAX THAN CHILD'''

def HeapifyMax(items,length,index):
    largest=index
    leftchild=(index*2)+1 #finding index of leftchild
    rightchild=(index*2)+2 #finding index of right child
    
    if leftchild<length and items[index]<items[leftchild]: #checking left chid exist and comparing with parent node
        largest=leftchild
        
    if rightchild<length and items[largest]<items[rightchild]: #checking right chid exist and comparing with parent node
        largest=rightchild
        
    if largest!=index: #swaping
        items[index],items[largest] = items[largest],items[index] 
        
        HeapifyMax(items,length,largest) #recurssion

'''HeapifyMin function, our root node is at index i. We will first assume that 
the value at index 'i' is the smallest. Then we will find index of left and right child.
Then we will check if left and right child exist or not.Now, we will compare our value 
at index i with left and right child. If either of two children have smaller value 
then "smallest" will store the index of greater value and will swap
the values. if the smallest is equal to index i then no swapping. This will be a recursive
funtion so that value gets to its correct position. MAKES PARENT MIN THAN CHILD'''

      
def HeapifyMin(items,length,index):
    smallest=index
    leftchild=(index*2)+1 #finding index of leftchild
    rightchild=(index*2)+2 #finding index of right child
    
    if leftchild<length and items[index]>items[leftchild]: #checking left chid exist and comparing with parent node
        smallest=leftchild
        
    if rightchild<length and items[smallest]>items[rightchild]: #checking right chid exist and comparing with parent node
        smallest=rightchild
        
    if smallest!=index: #swaping
        items[index],items[smallest] = items[smallest],items[index] 
        
        HeapifyMin(items,length,smallest)

'''HeapSortDes function will sort descending order.'''            

def HeapSortDes(items):
    length=len(items)
    MinHeap(items)
        
    for i in range(length-1, 0, -1): #extracting values one by one.
        items[i], items[0] = items[0], items[i]   # swaping 
        HeapifyMin(items, i, 0) 
        
    return items

'''HeapSortAsc function will sort descending order'''

def HeapSortAsc(items):
    length=len(items)
    MaxHeap(items)
        
    for i in range(length-1, 0, -1): #extracting values one by one.
        items[i], items[0] = items[0], items[i]   # swaping 
        HeapifyMax(items, i, 0) 
    
    return items


'''Now, we are creating our Max Heap function which will use Heapifymax function to place
values at their correct position.'''
        
def MaxHeap(items):
    length=len(items)
    for i in range(length // 2 - 1, -1, -1): #last parent node
        HeapifyMax(items,length,i) 
    
    return items

'''Now, we are creating our Min Heap function which will use HeapifyMin function to place
values at their correct position.'''
def MinHeap(items):
    length=len(items)
    for i in range(length // 2 - 1, -1, -1): #last parent node
        HeapifyMin(items,length,i) 
    return items

''' We will define our enqueue function which will recieve data
We will add it to the end of the heap and then move it to its
correct position.'''

def enqueue(items,data):
    items.append(data)
    return items

'''Let's define our DequeueMax function which will delete the highest priority element. 
There are 3 possibilities for the function.
First possibility that there are 2 or 3 values in the heap
in which we will move move max value to the end of the heap before popping it out
then we want to move the value that we swapped to the top position
The second possibility is that there is only one value in the heap.
In this case we can simply pop the top value from the heap then we will have 
empty heap after that.
The third possibility is that there is no element in the heap. In this case we
will just return "NO ELEMENT".'''

def DequeueMax(items):
    if len(items)>1: #first case
        swap(items,0,len(items)-1)
        maximum=items.pop()
        HeapifyMax(items,len(items),0)
        return maximum
        
    elif len(items)==1: #second case
        maximum=items.pop()
        return maximum
        
    else: #third case
        return "NO ELEMENT IN THE QUEUE "
 
    
'''Let's define our DequeueMin function which will dequeue the highest priority element. 
There are 3 possibilities for the function.
First possibility that there are 2 or 3 values in the heap
in which we will move move min value to the end of the heap before popping it out
then we want to move the value that we swapped to the top position
The second possibility is that there is only one value in the heap.
In this case we can simply pop the top value from the heap then we will have 
empty heap after that.
The third possibility is that there is no element in the heap. In this case we
will just return "NO ELEMENT".'''
    
def DequeueMin(items):
    if len(items)>1: #first case
        swap(items,0,len(items)-1)
        minimum=items.pop()
        HeapifyMin(items,len(items),0)
        return minimum
        
    elif len(items)==1: #second case
        minimum=items.pop()
        return minimum
        
    else: #third case
        return "NO ELEMENT IN THE QUEUE "

'''We will define Highestpriority function which will give the highest priority element. 
Highestpriority function simply checks to see if we have atleast one value on the heap.
If we do have then it will return the first value on a heap list. If we don't
have any value then it will simply returns "NO ELEMENT" i.e. heap is empty'''

def Highestpriority(items):
    if len(items)!=0:
        return items[0]
    
    else:
        return "NO ELEMENT IN THE QUEUE"
    


'''This is the python program in which we create the user input queue first then 
the choices will be asked to user. this runs in an infinite loop till the user 
choose to exit.'''
    
print("Python program to implement Priority Queue using Heap")
print("CREATE YOUR QUEUE")

'''User input queue''' 
myqueue=[]
n=int(input("Enter no. of elements you want in your queue:"))
for j in range(0,n):
    element=int(input("Enter element:"))
    myqueue.append(element)
print("Your Queue Is:",myqueue)

print("1.Create Your Max Priority Queue")
print("2.Create Your Min Priority Queue")

choice=int(input("Enter Your Choice:"))
if choice==1:
    print("Your Max Priority Queue Is:",HeapSortDes(myqueue)) #prints priority queue usin MaxHeap function
   
    while True:
        print("a. Enqueue in Priority Queue")
        print("b. Dequeue Highest Priority Element ")
        print("c. Highest Priority Element ")
        print("d. Exit ")

        option=input("Enter Your Choice:")

        if option=='a' or option=='A':
            value=int(input("Enter the value you want to insert in your priority queue:"))
            enqueue(myqueue,value)
            print("You New Priority Queue is:",HeapSortDes(myqueue))
        
        elif option=='b' or option=='B':
            k=DequeueMax(myqueue)
            print("Dequeued Highest priority elemnet is:", k)
            print("Your New Priority Queue is:", HeapSortDes(myqueue))
        
        elif option=='c' or option=='C':
            m=Highestpriority(myqueue)
            print("Highest priority element is:",m)
        
        elif option=='d' or option=='D':
            break
    
        else:
            print("INVALID CHOICE")

elif choice==2:
    print("Your Min Priority Queue Is:",HeapSortAsc(myqueue)) #prints priority queue usin MaxHeap function

    while True:
        print("a. Enqueue in Min Priority Queue")
        print("b. Dequeue Highest Priority Element ")
        print("c. Highest Priority Element ")
        print("d. Exit ")

        options=input("Enter Your Choice:")
        
        if options=='a' or options=='A' :
            value=int(input("Enter the value you want to insert in your priority queue:"))
            enqueue(myqueue,value)
            print("You New Priority Queue is:",HeapSortAsc(myqueue))
        
        elif options=='b' or options=='B':
            y=DequeueMin(myqueue)
            print("Dequeued Highest priority elemnet is:", y)
            print("Your New Priority Queue is:", HeapSortAsc(myqueue))
        
        elif options=='c' or options=='C':
            h=Highestpriority(myqueue)
            print("Highest priority element is:",h)
        
        elif options=='d' or options=='D':
            break
    
        else:
            print("INVALID CHOICE")

else:
    print("INVALID CHOICE")
