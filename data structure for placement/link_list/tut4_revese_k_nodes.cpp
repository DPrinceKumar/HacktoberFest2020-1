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

// node *revesrSimple(node *head){
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }
//     node *prev = NULL;
//     node *crr = head;
//     node *nxt  = crr->next;

//     while (crr != NULL)
//     {

//         nxt = crr->next;
//         crr->next = prev;
//         prev = crr;
//         crr = nxt;

//     }

//     return prev;
// }

// node *recurciveRevesetList(node *head){
    // if (head == NULL || head->next == NULL)
    // {
    //     return head;
    // }
    // node *reverse = recurciveRevesetList(head->next);
    // head->next->next = head;
    // head->next = NULL;

    // return reverse;

// }

node *recurciveRevesetList(node *head)
{
    node *prev = NULL;
    node *crr = head;
    node *nxt;

    while (crr != NULL)
    {
        nxt = crr->next;
        crr->next = prev;
        prev = crr;
        crr = nxt;
    }

    return prev;
}

node *revesreWithRecursion(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    cout<<head->data<<"->";
    node *reverse = revesreWithRecursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return reverse;
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
    node *head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    traverseLinkList(head);

    // head = recurciveRevesetList(head);
    // traverseLinkList(head);

    head = revesreWithRecursion(head);
    cout<<endl;
    // traverseLinkList(head);
    traverseLinkList(head);

    // head = revesrSimple(head);
    // traverseLinkList(head);

    return 0;
}