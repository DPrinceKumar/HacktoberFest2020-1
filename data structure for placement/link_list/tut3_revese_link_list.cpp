#include<bits/stdc++.h>
using namespace std;
class node{

    public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}; 
void insertAtTail(node* &head,int x){
    node *newnode = new node(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    // newnode->next = NULL;
    
}


    //  OR
node insertAtHead(node* &head,int x){
    node *n = new node(x);
    if (head == NULL)
    {
        head = n;
    }

    n->next = head;
    head = n;
}

void reveseList(node* &head){
    node *prev  = NULL;
    node *crr   = head;
    node *nxt   = crr->next;

    while (crr != NULL)
    {
        nxt = crr->next;
        crr->next = prev;
        prev = crr;
        crr = nxt;
        // nxt = nxt->next;

    }
    head = prev;
     
}

node* recurciveReveseList(node* &head){
    if (head == NULL || head->next ==NULL)
    {
        return head;
    }
    
    node *newhead = recurciveReveseList(head->next);
    head->next->next =  head;
    head->next = NULL;

    return newhead;
}
void traverseLinkList(node* head){
    node *temp = head;

    while (temp  != NULL)
    {
        cout<<temp->data<<"->";
        temp =temp->next;
    }
    
    cout<<"NULL"<<endl;
    
}
int main()
{

    // node *s = NULL;  ;
    // node *s2 =  new node(20);  ;
    // s->data = 10;
    // s->next = s2;
    // s2->data = 20;
    // s2->next =  NULL;

    // traverseLinkList(s);


    node *head = NULL;

    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);

    traverseLinkList(head);
    
    reveseList(head);
    traverseLinkList(head);

    head = recurciveReveseList(head);
    traverseLinkList(head);
    
    return 0;
}