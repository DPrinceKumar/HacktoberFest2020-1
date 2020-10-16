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
