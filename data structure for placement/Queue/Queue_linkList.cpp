#include<bits/stdc++.h>
using namespace std;
class node{

    public:
    int val;
    node *next;

    public:
    node(int x){
        val = x;
        next = NULL;
    }


};
class que{

    public:
    
    node *front;
    node *back;
    

    que (){
        front = NULL;
        back = NULL;
    }


    void push(int val){
        node *n = new node(val);
        if (front == NULL && back == NULL)
        {
            back = n;
            front = n;
            return;
        }
        
        
        back->next  = n;
        back = n;

    }


    void pop(){
        if (front == NULL)
        {
            cout<<"Queue is empty :( "<<endl;
            return;
        }
        node *delenode = front;
        // front = front.next   
        front = front->next;
        delete delenode;
    }

    int peek(){
        if (front == NULL)
        {
            cout<<"Queue is empty :( "<<endl;
            return -1;
        }

        return front->val;
    }

    bool isempty(){
        if (front == NULL)
        {
            // cout<<"Queue is empty :( "<<endl;
            return 1;
        }
        return 0;
    }

    void printQueue(){
        node *t = front;
        if (front == NULL)
        {
            cout<<"Queue is empty :( "<<endl;
            return ;
        }

        while(t!=NULL){
            cout<<t->val<<"->";
            t = t->next;
        }
        cout<<"NULL"<<endl;

    }
};




int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.printQueue();
    q.pop();
    q.pop();
    q.pop();
 
    q.printQueue();
    cout<<q.peek();
    
    return 0;
}