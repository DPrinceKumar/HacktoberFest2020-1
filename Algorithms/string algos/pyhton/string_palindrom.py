# Checking if the given string is palindrom or not.

s = 'Was it a cat I saw?'

# Solution-1:
# Solution uses extra space proportional to size of string "s"
s = ''.join([i for i in s if i.isalnum()]).replace(' ', '').lower()
print(s == s[::-1])


# Solution-2:
def is_palindrom(a):
    i = 0
    j = len(a) - 1

    while i < j:
        while not a[i].isalnum() and i < j:
            i += 1
        while not a[j].isalnum() and i < j:
            j -= 1

        if a[i].lower() != a[j].lower():
            return False
        i += 1
        j -= 1
    return True

a = 'Never odd or even!'
print(is_palindrom(a))