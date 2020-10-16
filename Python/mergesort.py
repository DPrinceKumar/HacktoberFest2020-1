import math

def merge(left_arr,right_arr):
    
    len_left = len(left_arr)
    
    len_right = len(right_arr)
    
    merge_arr = [0]*(len_left+len_right)
    
    left = 0
    
    right = 0
    
    for i in range(len(merge_arr)):
        
        if(left >= len_left):
            
            for j in range(right,len_right):
                
                merge_arr[i] = right_arr[j]
                
                i = i+1
                
            break
            
        if(right >= len_right):
            
            for j in range(left,len_left):
                
                merge_arr[i] = left_arr[j]
                
                i = i+1
                
            break
            
        if(left_arr[left] > right_arr[right]):
            
            merge_arr[i] = right_arr[right]
            
            right = right+1
            
        else:
            
            merge_arr[i] = left_arr[left]
            
            left = left+1
            
    return merge_arr

def mergeSort(num_arr):
    
    len_arr = len(num_arr)
    
    mid = math.floor(len_arr/2)
    
    if(len_arr == 1):
        
        return num_arr

    else:
        
        left_arr = mergeSort(num_arr[0:mid])
        
        right_arr = mergeSort(num_arr[mid:])
        
        return merge(left_arr,right_arr)
