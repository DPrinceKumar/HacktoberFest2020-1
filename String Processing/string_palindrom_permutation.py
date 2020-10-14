# Function to check if it is a permutation of a palindrome.

def is_palin_perm(in_str):
    in_str = in_str.replace(' ', '')
    in_str = in_str.lower()

    d = dict()
    for i in in_str:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    
    odd_count = 0
    for k, v in d.items():
        if v % 2 != 0 and odd_count == 0:
            odd_count += 1
        elif v % 2 != 0 and odd_count != 0:
            return False
    return True


# Testing
palin_perm = "Tact Coa"
not_palin_perm = "This is not a palindrome permutation"

print(is_palin_perm(palin_perm))
print(is_palin_perm(not_palin_perm))