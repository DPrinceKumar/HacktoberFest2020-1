def mfat(m):
    if m==0 or m==1:
        return 1
    else:
        return m*mfat(m-1)

def nfat(n):
    if n==0 or n==1:
        return 1

def multfatorial(m,n):
    if m>n:
        return mfat(m)/((nfat(n)*mfat(m-n)))
    else:
        print("Erro")
