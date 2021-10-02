#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        node * prev;
        node * next;

        node(int val){
            data = val;
            prev = NULL;
            next = NULL;
        }
};
void insertAtHead(node* &head, int val){
    
    node * n = new node(val);
    // cout<<n->data<<"sa"; 
    n->next = head;
    if (head!=NULL)
    {
        head->prev = n;
    }

    head = n;
    
}
void insertAtTail(node* &head,int val){
    node * n = new node(val);
    node *temp = head;
    if (head == NULL)
    {
        insertAtHead(head,val);
        /* code */
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next  = n;
    n->prev    = temp ;
    
    
}
void insertAtMid(node* &head,int pos,int val){
    node* temp = head;
    int c = 0;
    while (temp!=NULL && c != pos)
    {
        /* code */
        c++;
        temp = temp->next;
    }
    // cout<<temp->data<<endl;
    node *n = new node(val);
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;   
}
void travser(node* head){
    node *temp = head;
    int c = 0;
    while (temp!=NULL)
    {
        c++;
        cout<<temp->data<<"->";
        temp = temp->next;
    }   
    cout<<"NULL "<<c<<endl; 
}
int main()
{
    node *head = NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    travser(head);
    insertAtHead(head,05);
    insertAtTail(head,50);
    travser(head);
    insertAtMid(head,2,25);
    travser(head);

    return 0;
}