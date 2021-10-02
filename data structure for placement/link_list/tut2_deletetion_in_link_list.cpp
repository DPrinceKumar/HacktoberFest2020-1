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

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    traverseLinkList(head);

    // insertAtHead(head,05);
    // traverseLinkList(head);

    // insertAtPosition(head,100,2);
    // traverseLinkList(head);

    // deletiom

    // deleteHead(head);
    // traverseLinkList(head);

    // deleteAtEnd(head);
    // traverseLinkList(head);

    deleteAtPostion(head,3);
    traverseLinkList(head);
    return 0;
}