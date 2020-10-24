# Uses python3
import sys


def optimal_weight(W, w):
    w.insert(0,0)
    v=[[0 for _ in range(W+1)] for i in range(len(w))]
    for i in range(1,len(w)):
        for j in range(1,W+1):
            try:
                cur=v[i-1][j-w[i]]+w[i]
                if cur>j:
                    v[i][j]=max(v[i-1][j],v[i][j-1])
                else:
                    v[i][j]=max(v[i-1][j],v[i][j-1],cur)
            except:
                v[i][j]=max(v[i-1][j],v[i][j-1])
    for i in v:
        print(i)
    cur=v[-1][-1]
    used_items=[]
    for i in range(len(w),0,-1):
        if cur==0:
            break 
        if cur==v[i-1][-1]:
            continue
        else:
            cur=cur-w[i]
            used_items.append(w[i])
    print(used_items)
    return v[-1][-1]





if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
