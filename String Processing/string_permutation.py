# Given two strings, write a function to determine if one is a permutation of the other.

# Approach-1: Sorting
# TC: O(n log n)
# SC: O(1)
def is_permu1(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()

    if len(str1) != len(str2):
        return False
    
    str1 = ''.join(sorted(str1))
    str2 = ''.join(sorted(str2))

    n = len(str1)

    for i in range(n):
        if str1[i] != str2[i]:
            return False
    return True


# Approach-2: Hash table
# TC: O(n)
# SC: O(n)
def is_permu2(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()

    if len(str1) != len(str2):
        return False
    
    d = dict()
    for i in str1:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    for i in str2:
        if i in d:
            d[i] -= 1
        else:
            d[i] = 1
    
    return all(value == 0 for value in d.values())


# Testing
is_permutation_1 = "google"
is_permutation_2 = "ooggle"

not_permutation_1 = "not"
not_permutation_2 = "top"
print(is_permu1(is_permutation_1, is_permutation_2))
print(is_permu1(not_permutation_1, not_permutation_2))

print(is_permu2(is_permutation_1, is_permutation_2))
print(is_permu2(not_permutation_1, not_permutation_2))