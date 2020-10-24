#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int tmp = *xp;  
    *xp = *yp;  
    *yp = tmp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int ar[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (ar[j] > ar[j+1])  
            swap(&ar[j], &ar[j+1]);  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << ar[i] << " ";  
    cout << endl;  
}  
  
// Driver code  
int main()  
{  
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(ar)/sizeof(ar[0]);  
    bubbleSort(ar, n);  
    cout<<"Sorted array: \n";  
    printArray(ar, n);  
    return 0;  
}  

//Driver code by manpreet.
from sys import stdin
def bubbleSort(arr, n) :
    for i in range(n - 1) :
        for j in range(n - i - 1) :
            if arr[j] > arr[j+1] :
                temp = arr[j] 
                arr[j] = arr[j + 1]
                arr[j + 1] = temp 
def takeInput() : 
    n = int(input().strip()) 
    if n == 0 : 
        return list(), 0
    arr = list(map(int, input().strip().split(" "))) 
    return arr, n
def printList(arr, n) :
    for i in range(n) :
        print(arr[i], end = " ") 
    print() 
t = int(input().strip()) 
while t > 0 :
    arr, n = takeInput()
    bubbleSort(arr, n)
    printList(arr, n) 
    t-= 1


