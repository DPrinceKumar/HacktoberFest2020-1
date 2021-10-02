#include<bits/stdc++.h>
using namespace std;
#define n 10
class queues{
    public:
    int *arr;
    int front;
    int back;

    queues(){
        arr = new int[n];
        front = -1;
        back = -1;
    }    

    void push(int x);    
    void showQueue();    
    void pop();    
    int peak();    
};
void queues :: push(int x)
{
    if (back == n-1 )
    {
        cout<<"Queue is FUll"<<endl;
        return;
    }
    
    back++;
    arr[back] = x;
    if (front == -1)
    {
        front++;
    }
    
}


void queues :: showQueue(){
    if (back == -1 || front > back)
    {
        cout<<"Queue is empty : ( "<<endl;
        return;
    }
    for (int i = front; i <= back; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

void queues :: pop(){
    if (front == -1 || front > back)
    {
        cout<<"Queue is empty : ( "<<endl;
        return;        
    }
    front++;
    
}

int queues :: peak(){
    if (front == -1 || front > back)
    {
        cout<<"Queue is empty : ( "<<endl;
        return -1;        
    }
    return arr[front];
}
int main()
{
    queues q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(50);
    
    q.showQueue();   
    
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.showQueue();   
    
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(20);
    q.push(20);
    q.push(20);
    q.push(20);


    q.showQueue();   
    
    // cout<<q.peak();

    return 0;
}