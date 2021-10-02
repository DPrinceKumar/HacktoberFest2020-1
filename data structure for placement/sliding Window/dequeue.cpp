#include<bits/stdc++.h>
using namespace std;
void printdq(deque<int> dq){
    for (auto &&i : dq)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}    
int main()
{
    deque<int> dq;

    // dq.push_front(1);
    // dq.push_front(2);
    // dq.push_front(3);

    // printdq(dq);
    dq.push_front(1);
    dq.push_front(2);
    dq.push_front(-2);

    printdq(dq);
    // dq.pop_front();
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    printdq(dq);
    return 0;
}