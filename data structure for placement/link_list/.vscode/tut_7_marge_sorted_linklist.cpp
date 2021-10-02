#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insertAtTail(node *&head, int x)
{
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
void insertAtHead(node* &head, int x)
{
    node *n = new node(x);
    if (head == NULL)
    {
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

void insertAtPosition(node *&head, int x, int pos)
{
    node *n = new node(x);
    node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        if (c == pos)
        {
            break;
        }

        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}
void deleteHead(node* &head)
{
    if (head == NULL)
    {
        cout << "List is Empty :( " << endl;
        return;
    }

    head = head->next;
}

void deleteAtEnd(node *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty :( " << endl;
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // cout<<temp->data<<endl;
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPostion(node *head, int pos)
{
    if (pos == 1)
    {
        deleteHead(head);
        return;
    }
    
    if (head == NULL)
    {
        cout << "List is Empty :( " << endl;
        return;
    }
    int c = 1;
    node * temp = head;
    while (temp->next != NULL)
    {
        c++;
        if (c == pos)
        {
            break;
        }
        temp = temp->next;
    }
    temp->next = temp->next->next;
    // cout<<temp->data<<endl;
    

}

void traverseLinkList(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
void marge(node* &h1, node* &h2){
    node *dummy = new node(-1);
    node *t = dummy;
    node *temp1 = h1;
    node *temp2 = h2;

    while (temp1!=NULL && temp2!=NULL)
    {

        if (temp1->data < temp2->data)
        {
            t->next = temp1;
            temp1 = temp1->next;
        }
        else{
            t->next = temp2;
            temp2 = temp2->next;
        }

        t = t->next;

        
        
    }
    while (temp1!=NULL)
    {
        t->next  = temp1;
        temp1  = temp1->next;
        t = t->next;
        // temp2 = temp2->next;
    }
    
    while (temp2!=NULL)
    {
        t->next  = temp2;
        temp2  = temp2->next;
        t = t->next;
        // temp1 = temp1->next;
    }
    h1 = dummy->next;
    
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

    node *h1 = NULL;
    node *h2 = NULL;

    insertAtTail(h1, 10);
    insertAtTail(h1, 20);
    insertAtTail(h1, 30);
    insertAtTail(h1, 40);
    insertAtTail(h1, 50);

    insertAtTail(h2, 15);
    insertAtTail(h2, 25);
    insertAtTail(h2, 35);
    insertAtTail(h2, 45);
    insertAtTail(h2, 55);
    insertAtTail(h1, 65);
    insertAtTail(h2, 75);


    marge(h1,h2);
    traverseLinkList(h1);

    // insertAtHead(head,05);
    // traverseLinkList(head);

    // insertAtPosition(head,100,2);
    // traverseLinkList(head);

    // deletiom

    // deleteHead(head);
    // traverseLinkList(head);

    // deleteAtEnd(head);
    // traverseLinkList(head);

    // deleteAtPostion(head,3);
    // traverseLinkList(head);
    return 0;
}