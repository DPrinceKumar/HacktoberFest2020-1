#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
            {
                st.pop();
            }else{
                st.push(s[i]);
            }
                        
        }
        
        
    }
    if (st.empty())
    {
        return true;
    }
     
    return false;
    
    
}
int main()
{
    string s;
    cin>>s;

    if (check(s))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    

    return 0;
}