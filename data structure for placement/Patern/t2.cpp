#include<bits/stdc++.h>
using namespace std;
    
/*
* * * * *
* * * * 
* * *
* *
*

*/

// 1} identify number of woe
// 2) identfy how many coloum are there

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
            for (int j = 0; j < n-i; j++)
            {
                cout<<"* ";
            }
            cout<<endl;
            
    }
    
    
    return 0;
}