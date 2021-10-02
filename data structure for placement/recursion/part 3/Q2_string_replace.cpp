#include<bits/stdc++.h>
using namespace std;
void rep(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    string ROS;
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout<<"3.14";
        ROS = s.substr(2);
    }
    else{
        cout<<s[0];
        ROS = s.substr(1);
    }
    rep(ROS);
}
int main()
{
    rep("pisssssssssssspidpi") ;
    return 0;
}