n = int(input())
sum1=0
for i in range(n):
    s = input()
    if(s==s[::-1]):
        sum1 += len(s)
print(sum1)
