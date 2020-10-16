from collections import Counter
t=int(input())
for i in range(t):
    n=int(input())
    numbers=[int(x) for x in input().split()]
    freq=Counter(numbers)
    arr=list(freq.values())
    countarr=Counter(arr)
    a=0
    b=11111111
    for j in countarr.keys():
        k=countarr.get(j)
        if(a==k):
            b=min(b,j)
            a=k
        elif(k>a):
            b=j
            a=k
    print(b)
