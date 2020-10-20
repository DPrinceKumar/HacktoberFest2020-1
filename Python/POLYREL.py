T= int(input())
for i in range(0,T):
    N= int(input())
    for i in range(N):
        ls= list(map(int, input().split(' ')))
    sum = N
    while(N>=6):
        N=int(N/2)
        sum+=N
    print(sum)
