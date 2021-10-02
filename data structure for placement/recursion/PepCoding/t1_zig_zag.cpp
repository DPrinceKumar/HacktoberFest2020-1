#include<bits/stdc++.h>
using namespace std;
void fun(int n){
    if (n == 0)
    {
        return;
    }
    
    cout<<"Pre :"<<n<<endl;
    fun(n-1);
    cout<<"Pre :"<<n<<endl;
    fun(n-1);
    cout<<"Pre :"<<n<<endl;
}
int main()
{
    fun(2);
    return 0;
}