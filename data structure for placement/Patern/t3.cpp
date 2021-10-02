#include<bits/stdc++.h>
using namespace std;
    
/*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5

*/

// 1} identify number of woe
// 2) identfy how many coloum are there

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   
        int it = 1;
            for (int j = 0; j < i+1; j++)
            {
                cout<<it++<<" ";
            }
            cout<<endl;
            
    }
    
    
    return 0;
}