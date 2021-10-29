#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}NODE;
void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
NODE* solve(NODE*);//function to solve the problem

NODE* createNode(int);
NODE* solve(NODE*);
int main(){
    NODE* head=input();
    printList(solve(head));
    return 0;
}
NODE* solve(NODE* A){
    if(A==NULL||A->next==NULL)
        return A;
    NODE* ptr=A,*pre=A->next,*root=createNode(-1),*ans=root;
    int flag;
    while(pre!=NULL){
        flag=0;
        if(ptr->data==pre->data){
            while(pre!=NULL&&ptr->data==pre->data){
                ptr=pre;
                pre=pre->next;
            }
            flag=1;
        }
        else{
            ans->next=ptr;
            ans=ans->next;
        }
        ptr=pre;
        if(pre)
            pre=pre->next;
        if(flag==1&&pre==NULL){
            ans->next=ptr;
            ans=ans->next;
        }
    }
    //if(root->next!=NULL)
        return root->next;
}
void printList(NODE* head){
    NODE* ptr=head;
    if(head==NULL)
        return;
    while(ptr!=NULL){
        if(ptr!=head)
            printf("->");
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}//Fuction used to print the linked list
NODE* createNode(int dt){
    NODE* n=(NODE*)malloc(sizeof(NODE));
    n->data=dt;
    n->next=NULL;
    return n;
}//Function that creates and returns a pointer to a NODE
NODE* input(){
    NODE* head=NULL,*tail=NULL,*pt;
    int num,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        pt=createNode(num);
        if(head==NULL)
            head=tail=pt;
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;
}//function that takes in the input in the form of a linked list and returns the head
