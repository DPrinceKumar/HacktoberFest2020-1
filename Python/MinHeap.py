#Min Heap
def heapify(li, x, n):
    largest = x
    left = 2 * x + 1
    right = 2 * x + 2 
    if (left < n and  li[left] < li[largest]) or (right < n and li[right] < li[largest]):
        #print(li[x], x)
        if left < n and li[left] < li[largest]: #cheking if left child is exist and its value is less than largest node or not
            li[x], li[left] = li[left], li[x]
            heapify(li, left, n)
        elif right < n: #We just have to check right because if left is not exist then right cannot be exist. 
            li[x], li[right] = li[right], li[x]
            heapify(li, right, n)
        

li = [3,9,2,1,4,5]
n = len(li)
for x in range((n // 2) - 1, -1, -1):
    heapify(li, x, n)

print(li)
