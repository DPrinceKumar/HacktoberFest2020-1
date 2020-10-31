# Execute the program as: ./snail_sorting.py "123" "456" "789"
# You can change the number values as long as there are the same number of digits as numbers. 
# Valid Examples: "123" "456" "789" // "12345" "34456" "22445" "15567" "56767"

#!/usr/bin/env python3

import sys

def usage():
	print(f"usage: ./{sys.argv[0]} <1-9 squared_rows...>")
	sys.exit()

def fail_check():
	if len(sys.argv) < 2 or len(sys.argv) > 21:
		return usage()
	for i in range(1, len(sys.argv)):
		if len(sys.argv) - 1 != len(sys.argv[i]):
			return usage()

def snailing(array):
	string = []
	row_begin = 0
	row_end = len(array) - 1
	col_begin = 0
	col_end = len(array[0]) - 1

	while row_begin <= row_end and col_begin <= col_end:
		for i in range(col_begin, col_end + 1):
			string.append(array[row_begin][i])
		row_begin += 1

		for i in range(row_begin, row_end + 1):
			string.append(array[i][col_end])
		col_end -= 1
		
		if row_begin <= row_end:
			for i in range(col_end, col_begin -1, -1):
				string.append(array[row_end][i])
		row_end -= 1

		if col_begin <= col_end:
			for i in range(row_end, row_begin -1, -1):
				string.append(array[i][col_begin])
		col_begin += 1

	return string

def main():
	fail_check()
	array = sys.argv[1:]
	for x in array:
		if x.isnumeric() == False:
			return usage()
	print(*snailing(array), sep=", ")

if __name__ == "__main__":
	main()