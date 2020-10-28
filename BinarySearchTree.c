/*
This program implements the insertion of a Binary Search Tree and its functions(Searching, Finding MIN & MAX, Traversal) as well.

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
}*root = NULL, *newNode, *current;

//creating a new node for the tree
struct node* create(int item)
{
    //create node
    newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//inserting the new node to the tree
void insert(struct node* current, struct node* newNode)
{
    //insert as a leaf to the node 
    if(root == NULL)
    {
        root = newNode;
        return;
    }
    else if (current->data > newNode->data)
    {
        if (current->left == NULL)
            current->left = newNode;
        else
            insert(current->left, newNode);
    }   
    else
    {
        if (current->right == NULL)
            current->right = newNode;
        else
            insert(current->right, newNode);
    }
    
        
}

//finding the node with the MIN key value
void find_MIN(struct node *current)
{
    if(current->left != NULL)
        find_MIN(current->left);
    else
        printf("\nMIN node key: %d\n", current->data);
        return;
}

//finding the node with the MAX key value
void find_MAX(struct node *current)
{
    if(current->right != NULL)
        find_MIN(current->right);
    else
        printf("\nMIN node key: %d\n", current->data);
        return;
    
}

//This function traverses the tree in preorder fashion
void preorder(struct node *node)
{
    if(node != NULL)
    {
        printf("\n%d", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

//This function traverses the tree in inorder fashion
void inorder(struct node *node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("\n%d", node->data);
        inorder(node->right);
    }
}

//This function traverses the tree in postorder fashion
void postorder(struct node *node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("\n%d", node->data);
    }
}



//Searching whether an Node exists or not
int search(struct node *current, int se)
{
    if(current == NULL)
    {
        return 0;
    }
    if(se == current->data)
    {
        printf("\nThe key %d is found in the tree\n", se);
        return 1;
    }
    else if(se < current->data)
        search(current->left, se);
    else   
        search(current->right, se);
}


void main()
{
    int choice, item, se, result;
    struct node* new;
    while(1)
    {
    printf("\n---------ENTER YOUR CHOICE--------------\n");
    printf("  1.BST insertion\n  2.Find MIN\n  3.Find MAX\n  4.Search for the key\n  5.Traversal(Inorder)\n  5.Traversal(Preorder)\n");
    printf("  6.Traversal(Inorder)\n  7.Traversal(Postorder)\n  8.Exit\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:{
            printf("\nEnter the item you want to insert: ");
            scanf("%d", &item);
            new = create(item);
            insert(root, new);
            break;
        }
        case 2:{
            if(!root)
            {
                printf("\nTree is Empty. Please enter nodes first\n");
                break;
            }
            find_MIN(root);
            break;
        }
        case 3:{
            if(!root)
            {
                printf("\nTree is Empty. Please enter nodes first\n");
                break;
            }
            find_MAX(root);
            break;
        }
        case 4:{
            if(!root)
            {
                printf("\nTree is Empty. Please enter nodes first\n");
                break;
            }
            printf("Enter the key you want to search");
            scanf("%d", &se);
            result = search(root, se);
            if(result == 0)
                printf("Node doesnt exist");
            break;
        }
        case 5:{
            if(!root)
            {
                printf("\nTree is Empty. Please enter nodes first\n");
                break;
            }
            printf("\n-------Traversal(PREORDER)-------\n");
            preorder(root);
            break;
        }
        case 6:{
            if(!root)
            {
                printf("\nTree is Empty. Please enter nodes first\n");
                break;
            }
            printf("\n-------Traversal(INORDER)-------\n");
            inorder(root);
            break;
        }
        case 7:{
            if(!root)
            {
                printf("\nTree is Empty. Please enter nodes first\n");
                break;
            }
            printf("\n-------Traversal(POSTORDER)-------\n");
            postorder(root);
            break;
        }
        case 8:{
            exit(0);
        }
    }
    }
    

}
