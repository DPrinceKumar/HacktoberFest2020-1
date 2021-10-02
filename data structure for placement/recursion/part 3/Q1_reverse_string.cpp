#include<bits/stdc++.h>
using namespace std;
void rev(string s)
{
    if (s.length()==0)
    {
        return;
    }
    string rest_of_string = s.substr(1);
    rev(rest_of_string);
    cout<<s[0];
}    
int main()
{
    rev("dipak");
    return 0;
}