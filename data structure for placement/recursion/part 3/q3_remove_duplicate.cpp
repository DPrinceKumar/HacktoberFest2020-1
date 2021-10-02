#include<bits/stdc++.h>
using namespace std;
string RD(string s)
{
    if (s.length() == 0)
    {
        return ""   ;
    }
    char ch = s[0];
    string ans = RD(s.substr(1));
    if (ch == ans[0])
    {
        return (ans);
    }
    else{

        return(ch+ans);
    }
    
}
int main()
{
    cout<<RD("aaaaabcdddd");
    return 0;
}