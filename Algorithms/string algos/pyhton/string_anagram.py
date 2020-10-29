# Find if given two strings are anagram of each other.

# Solution-1:
s1 = 'Madam curie'
s2 = 'Radium came'

s1 = s1.replace(' ', '').lower()
s2 = s2.replace(' ', '').lower()

# Requires n log n time (since any comparison 
# based sorting algorithm requires at least 
# n log n time to sort).
print(sorted(s1) == sorted(s2))


# solution-2:
def is_anagram(a1, a2):
    ht = dict()

    if len(a1) != len(a2):
        return False
    
    for i in a1:
        if i in ht:
            ht[i] += 1
        else:
            ht[i] = 1
    for i in a2:
        if i in ht:
            ht[i] -= 1
        else:
            ht[i] = 1
    for i in ht:
        if ht[i] != 0:
            return False
    return True


a1 = 'Fairy Tales'
a2 = 'Rail Safety'

a1 = a1.replace(' ', '').lower()
a2 = a2.replace(' ', '').lower()

print(is_anagram(a1, a2))