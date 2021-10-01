Num=int(input())
i=1

#Sum variable is used To Keep Track of Sum of Even
sum=0
#Sum1 Variable is used to Keep track of sum of odds
sum1=0

d=(len(str(Num)))

n=Num
# Seperate the input number after number
while i<=d:
    l=n%10
    n=n//10
    #Check whether the number is even
    if l%2==0:
        sum=sum+1
    #If Number is odd
    else:
        
        sum1=sum1+l
    #To iterate to the length of input    
    i=i+1
    
        
print (sum ,sum1)
