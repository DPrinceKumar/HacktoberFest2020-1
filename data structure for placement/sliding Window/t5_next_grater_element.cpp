#include<bits/stdc++.h>
using namespace std;
    
int main()
{
    int a[] = {1,2,5,12,8,7,10,3,5,9};
    stack<int> st;
    int n  = sizeof(a)/sizeof(a[0]);

    for (int i = n-1; i >= 0; i--)
    {
        // if (st.empty())
        // {
        //     cout<<-1<<endl;
        //     st.push(a[i]);
        //     continue;
        // }
        while (!st.empty() &&  st.top() <= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            cout<<-1<<endl;
            // continue;
        }else{
            cout<<st.top()<<endl;

        }

            st.push(a[i]);

        
        

        
    }
    
    return 0;
}