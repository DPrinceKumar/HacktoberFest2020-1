n = int(input())
cost = [0 for i in range(n)]
weight = [0 for i in range(n)]

cost = [int(j) for j in input().strip().split(" ")]
weight = [int(j) for j in input().strip().split(" ")]



target = int(input())

dp = [0 for i in range(target+1)]

for i in range(1,target+1):
    for j in range(n):
       if weight[j]<=i:
            dp[i] = max(dp[i],cost[j]+dp[i-weight[j]])

print(dp)
