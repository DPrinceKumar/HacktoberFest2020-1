#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    int a[] = {1,2,1,2,1,2,1,2,99};
    int n = sizeof(a)/sizeof(a[0]);
    int temp = a[0];
    for (int i = 1; i < n; i++)
    {
        temp = temp ^ a[i];
        

    }
    cout<<temp;
    
    return 0;
}