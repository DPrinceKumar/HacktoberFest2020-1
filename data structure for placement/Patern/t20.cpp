#include<bits/stdc++.h>
using namespace std;
    
/*
         *   
        * *
       * * *
      * * * *
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
   int n ;
    cin>>n;
    bool f = true;
    bool st = true;
    int c = 0;
    int ct = 5;
    for (int i = 0; i < (2*n); i++)
    {   

        c = i>n ? 2*n-i : i;
        
        for (int k = 0; k < n-c; k++)
        {
            cout<<" ";
        }
        
                int temp = i; 
            for (int j = 0; j < c; j++)
            {
                cout<<abs(temp--)<<" ";
            }
            cout<<endl; 
            
    }
    
    
    return 0;
}

https://www.google.com/search?q=Google&oi=ddle&ct=174788361&hl=en-GB&si=AHuW2sTKkcygiABA_QY_APML0LA-zLeY72p7cWUnG9AtyAalP1i53_krmmvC13Fdies6c3DHfW4HDEWuVKF-2lUnrwn7wmvX2_-nc3qI02CTiHgQwXfgST4%3D&source=doodle-ntp&ved=0ahUKEwjhhoOZy5_zAhUY3jgGHcx9CSkQPQgB