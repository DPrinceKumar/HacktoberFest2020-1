pno=0
cno=0
no=0
c=0
iscomp=0
while (no!=-1):
    no=int(input("\n Enter the no"))
    iscomp=0
    for c in range(2,no):
        if (no%c==0):
            iscomp=1
            break
            


    if (iscomp==1):
        cno+=1
        print(cno , end ="  ",)
        
    else: pno+=1

print("the no of prime nos are ",pno-1)
print("the no of composite nos are ", cno)
    
