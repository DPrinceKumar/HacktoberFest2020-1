 #Among all the substrings of length 2 of a given string s, print the substring which is most frequent. If there are multiple answers, print the lexicographically smallest substring

# CODE
#length of string
leng = int(input("LENGTH OF STRING : "))
#Input string
str1 = input("STRING :")
bigcount = None 
bigword = None
count = dict()  #stores substring and their occurances
res = [str1[i: i+2] for i in range(leng-1)]
for i in res:
    count[i] = count.get(i, 0)+1    #counts the occurances of substrings
count = dict(sorted([(key, val) for key, val in count.items()]))    #to sort substrings in descending order
for wd, cnt in count.items():
    if bigcount is None or cnt > bigcount:
        bigword = wd
        bigcount = cnt
print(bigword)
