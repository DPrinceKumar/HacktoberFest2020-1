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

void traverseLinkList(node* head){
    node *temp = head;

    while (temp  != NULL)
    {
        cout<<temp->data<<"->";
        temp =temp->next;
    }
    
    cout<<"NULL"<<endl;
    
}

 bool isPalindrome(node* head) {
     node* temp = head;
     vector<int>v;
     while (temp != NULL)
     {
        v.push_back(temp->data);
         temp = temp->next;

     }

     for (int i = 0; i < v.size()/2; i++)
     {
         if (v[i] != v[(v.size())-1-i])
         {
            return false;
         }
         
     }
     
     return true;
}





  node* addTwoNumbers(node* l1, node* l2) {
        node *dumynode = new node(-1);
        node *temp1 = l1 ;
        node *temp2 = l2 ;
        node *ansNode = dumynode;
        int carry = 0;
        while(temp1!=NULL && temp2!= NULL){
            int sum = temp1->data +temp2->data;
            sum = sum + carry; 
            // cout<<sum<<endl;
            int ansss = sum%10;
            
            node *t = new node(ansss);
            
            dumynode->next = t;

            
            if(sum>9){
                carry = 1;
            }
            else{
                carry = 0;
               
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
            dumynode = dumynode->next;

        }
        
        
        while(temp1!=NULL){
            // cout<<"1"<<endl;
              int sum = temp1->data ;
            sum = sum + carry; 
              int ansss = sum%10;
            
            node *t = new node(ansss);
            
            dumynode->next = t;

                 if(sum>9){
                carry = 1;
            }
            else{
                carry = 0;
            }
            temp1 = temp1->next;
            dumynode = dumynode->next;
        }
        
        while(temp2!=NULL){
             int sum = temp2->data;
            sum = sum + carry; 
              int ansss = sum%10;
            
            node *t = new node(ansss);
            
            dumynode->next = t;

                 if(sum>9){
                carry = 1;
            }
            else{
                carry = 0;
            }
            temp2 = temp2->next;
            dumynode = dumynode->next;
        }        
        
        
        if(carry == 1){
              node *t ;
              dumynode->next = t;
                t->data = 1;
             dumynode = dumynode->next;
        }
        return ansNode->next; 
    }



int lenghtOflist(node* head){
    node * temp = head;
    int c = 0;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    return c;
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


    node *head1 = NULL;
    node *head2 = NULL;

    insertAtTail(head1,9);
    insertAtTail(head1,9);
    insertAtTail(head1,9);
    insertAtTail(head1,9);
    insertAtTail(head1,9);
    insertAtTail(head1,9);
    insertAtTail(head1,9);

    insertAtTail(head2,9);
    insertAtTail(head2,9);
    insertAtTail(head2,9);
    insertAtTail(head2,9);
    traverseLinkList(head1);
    
    // cout<<isPalindrome(head)<<endl;
    // traverseLinkList(head);

    // node *ans = addTwoNumbers(head1,head2);
    // traverseLinkList(ans);
    cout<<lenghtOflist(head1);
    return 0;
}