#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int flag = 0;
        int n, k, x,y;
        cin>>n>>k>>x>>y;
        for(int i = 0; i <= n; i++)
        {
            if((x+k*i)%n == y)
            {
                cout<<"YES"<<endl;
                flag = 1;
                break;
            }
        }
            if(flag == 0)
            {
                cout<<"NO"<<endl;
        }
}
}
