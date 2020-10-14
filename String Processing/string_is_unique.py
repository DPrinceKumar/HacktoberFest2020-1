# determine if a string has all unique characters.

def is_unique(input_str):
    d = dict()
    input_str = input_str.replace(' ', '')
    input_str = input_str.lower()

    for i in input_str:
        if i in d:
            return False
        else:
            d[i] = 1
    return True


# Testing
input_str = 'tattoo'
str_1 = 'not game '

print(is_unique(input_str))
print(is_unique(str_1))