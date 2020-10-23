def search_binary(sorted_array, target):

    left = 0

    right = len(sorted_array) - 1

    while left <= right:

        midpoint = left + (right - left) // 2

        current = sorted_array[midpoint]

        if current == target:

            return midpoint

        else:

            if target < current:

                right = midpoint - 1

            else:

                left = midpoint + 1

    return None

 

target = 5

sorted_array = [0, 1, 2, 3, 4, 5]

result = search_binary(sorted_array, target)

if result is not None:

    print('Value {} found at position {} using binary search'.format(target, result+1))

else:

    print('Not found')
