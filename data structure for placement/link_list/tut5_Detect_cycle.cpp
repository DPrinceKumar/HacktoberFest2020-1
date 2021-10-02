#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
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
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

node *removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;

        if (fast == slow)
        {
            break;
        }
    }
    fast = head;

    while (slow->next != fast->next)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast == slow)
        {
            break;
        }
    }
    slow->next = NULL;
    return head;

    // return false;
}
int main()
{
    node *head = new node(10);
    node *f = new node(20);
    node *s = new node(30);
    node *t = new node(40);
    node *ft = new node(60);
    node *sx = new node(70);
    node *sv = new node(80);
    node *eg = new node(90);
    node *tn = new node(100);
    // head->data = 50;
    head->next = f;
    f->next = s;
    s->next = t;
    t->next = ft;
    ft->next = sx;
    sx->next = sv;
    sv->next = eg;
    eg->next = tn;
    // tn->next = NULL;
    // eg->next = t;
    // traverseLinkList(head);
    // if (cout<<detectCycle(head)<<endl)
    // {
    //     head = removeCycle(head);
    // }
    // cout<<endl;

    traverseLinkList(head);
    return 0;
}