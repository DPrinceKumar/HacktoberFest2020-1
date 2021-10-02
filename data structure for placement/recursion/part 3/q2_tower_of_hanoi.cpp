#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char src, char dest, char hper){
    if (n == 0)
    {
        return;
    }
    
    TOH(n-1,src,hper,dest);
    cout<<"move frome "<<src<<" to "<< dest<<endl;
    TOH(n-1,hper,dest,src);

} 
int main()
{
    TOH(3,'a','c','b');
    return 0;
}