#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    int sum  = 0;
    inorder(root->left);
    cout <<"node "<< root->data << " ";
    inorder(root->right);
    sum+= root->data;


    cout<<sum<<endl;

}
int main()
{

    node *root = new node(100);
    node *n1 = new node(50);
    node *n2 = new node(150);
    node *n3 = new node(25);

    root->left = n1;
    root->right = n2;
    n1->left = n3;

    inorder(root);
    return 0;
}