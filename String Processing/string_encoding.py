'''
Problem: Implementing a function that converts a spreadsheet column
ID (i.e., “A”, “B”, “C”, …, “Z”, “AA”, etc.) to the corresponding integer.

For example, “A” equals 1 because it represents the first column,
while “AA” equals 27 because it represents the 27th column.
'''

def spreadsheet_encode(col_str):
    num = 0
    count = len(col_str) - 1
    for s in col_str:
        # ord() returns an integer which represents the Unicode
        # code point of the Unicode character passed into the function.
        num += 26 ** count * (ord(s) - ord('A')+1)
        count -= 1
    return num


# Testing
print(spreadsheet_encode('Mai'))