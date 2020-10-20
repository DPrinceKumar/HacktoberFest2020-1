#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    long long n,i,max=0,c=1;
    string s;
    cin>>s;
    char a = s[0];
    n = s.length();
    for(i=1;i<n;i++)
    {
        if(a == s[i])
        {
            c++;
            continue;
        }
        else
        {
            if(c > max)
                max = c;
            a = s[i];
            c=1;
        } 
    }
    if(c > max)
        max = c;
    cout<<max;
}