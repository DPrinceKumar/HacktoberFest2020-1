#Selection Sort code in Python 
# Author:@FaizAlam
#  
import sys 
A = [15,14,18,30,6,42,1] 
  
# Traverse through all array elements 
for i in range(len(A)): 
      
    # Find the minimum element in remaining unsorted array 
    min_i = i 
    for j in range(i+1, len(A)): 
        if A[min_i] > A[j]: 
            min_i = j 
              
    # Swap the found minimum element with the first element         
    A[i], A[min_i] = A[min_i], A[i] 
  

print ("Sorted array: ") 
for i in range(len(A)): 
    print(A[i])  