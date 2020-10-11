'''
Problem: Look and Say
To generate a member of the sequence from the previous member,
read off the digits of the previous member and record the count
of the number of digits in groups of the same digit.

Ex.: 111221 is read off as "three 1s, two 2s, then one 1" or 312211.
'''

def next_number(s):
    result = []
    i = 0

    while i < len(s):
        count = 1

        while i + 1 < len(s) and s[i] == s[i+1]:
            i += 1
            count += 1
        result.append(str(count) + s[i])
        i += 1

    return ''.join(result)


# Testing
s = '11'
print(next_number(s))

u = '1112211'
print(next_number(u))