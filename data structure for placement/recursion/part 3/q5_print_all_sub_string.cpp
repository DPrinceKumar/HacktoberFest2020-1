#include<bits/stdc++.h>
using namespace std;
void substrs(string s,string ans)
{
    if (s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    
    char ch = s[0];
    string ros = s.substr(1);
    substrs(ros,ans); 
    // cout<<endl;
    substrs(ros,ans+ch); 
}
int main()
{
    substrs("abc","");    
    return 0;
}
