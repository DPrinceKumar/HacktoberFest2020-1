#include<bits/stdc++.h>
using namespace std;
string rep(string s){
    if (s.length() == 0)
    {
        return "";
    }
    char fc = s[0];
    string ans = rep(s.substr(1));
    if (fc == 'x')
    { 
        return ans + fc;
    }
    return fc + ans;
    
    
}
int main()
{
    cout<<rep("aaxxxadadxadadx");
    return 0;
}