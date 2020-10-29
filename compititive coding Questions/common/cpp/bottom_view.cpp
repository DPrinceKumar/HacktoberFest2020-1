//P.S bottom view is not equal to printing all leaf nodes

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    int hd; //horizontal distance 
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        hd=INT_MAX;
        left=right=NULL;
    }

};

node* buildtree()
{
    int d;
    cin>>d;

    if(d==-1)
     return NULL;
    
    node* new_node= new node(d);
    new_node->left=buildtree();
    new_node->right=buildtree();
    return new_node;
}

void bottomView(node *root) 
{ 
    if (root == NULL) 
        return; 
  
    // Initialize a variable 'hd' with 0 
    // for the root element. 
    int hd = 0; 
  
    // TreeMap which stores key value pair 
    // sorted on key value 
    map<int, int> m; 
  
    // Queue to store tree nodes in level 
    // order traversal 
    queue<node *> q; 
  
    // Assign initialized horizontal distance 
    // value to root node and add it to the queue. 
    root->hd = hd; 
    q.push(root);  // In STL, push() is used enqueue an item 
  
    // Loop until the queue is empty (standard 
    // level order loop) 
    while (!q.empty()) 
    { 
        node *temp = q.front(); 
        q.pop();   // In STL, pop() is used dequeue an item 
  
        // Extract the horizontal distance value 
        // from the dequeued tree node. 
        hd = temp->hd; 
  
        // Put the dequeued tree node to TreeMap 
        // having key as horizontal distance. Every 
        // time we find a node having same horizontal 
        // distance we need to replace the data in 
        // the map. 
        m[hd] = temp->data; 
  
        // If the dequeued node has a left child, add 
        // it to the queue with a horizontal distance hd-1. 
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
  
        // If the dequeued node has a right child, add 
        // it to the queue with a horizontal distance 
        // hd+1. 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    } 
  
    // Traverse the map elements using the iterator. 
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 
}

int main()
{
    node* root=buildtree();
    bottomView(root);

}

/* 

8
10
1
-1
-1
6
9
-1
-1
7
-1
-1
3
-1
14
13
-1
-1
-1


*/