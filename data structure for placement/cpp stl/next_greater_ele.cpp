#include<bits/stdc++.h>
using namespace std;
vector<int> nxtGreater(vector<int> v)
{
    stack<int> st;
    vector<int> temp(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[ st.top()])
        {
            temp[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty( ))
    {
        temp[st.top()] = -1;
        st.pop();
    }
    

    return temp;    
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    vector<int> tp = nxtGreater(v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" "<<(tp[i] == -1? -1 : v[tp[i]] )<<endl;
    }
    
    
    return 0;
}