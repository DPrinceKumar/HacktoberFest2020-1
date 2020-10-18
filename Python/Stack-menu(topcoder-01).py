stack=[] #global stack tht is an empty list

def push(val):
    stack.append(val)
    print('Value',val,'pushed to stack')

def Pop():
    if len(stack)==0:#if stack==[]
        print('underflow stack is empty')
    else:
        print('value popped=',stack.pop())

def display():

    if len(stack)==0:
        print('Underflow stack is empty')
        return
    # 0  1  2      len(stack)=3
    #[10,20,30]
                    #[2,1,0]
    for i in range(len(stack)-1,-1,-1): #reverse loop to display the stack in LIFO order
        print(stack[i])
        
while True:
    
    print("--------------STACK OPERATIONS----------------")

    print("1. PUSH")
    print("2. POP")
    print("3. DISPLAY")
    print("4. EXIT")
    ch=int(input("Enter your choice:"))
    if ch==1:
        val=int(input("Enter the value to be pushed to stack::"))
        push(val)
    elif ch==2:
        Pop()
    elif ch==3:
        display()
    elif ch==4:
        break
print("bye bye......")
