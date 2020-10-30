print("hi im shahin please merge this code")

def selection_sort(A):
    for i in range(len(A)-1,0,-1):
            max_position = 0
            for j in range(1, i+1):
                if A[j] > A[max_position]:
                    max_position = j
                temp = A[i]
                A[i] = A[max_position]
                A[max_position] = temp
