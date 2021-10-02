#include<bits/stdc++.h>
using namespace std;
    
/*
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
*/

// 1} identify number of woe
// 2) identfy how many coloum are there

int main()
{
    int n ;
    cin>>n;
    bool f = true;
    int c = 0;
    for (int i = 0; i < (2*n); i++)
    {   
        if (c<=n && f)
        {
            c++;
        }
        else{
            f = false;
            c--;
        }
        
            for (int j = 0; j < c; j++)
            {
                cout<<"* ";
            }
            cout<<endl; 
            
    }
    
    
    return 0;
}