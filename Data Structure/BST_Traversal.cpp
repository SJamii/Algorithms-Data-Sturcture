// Binary tree traversal.
// Time Complexity: O(n).

#include<bits/stdc++.h>
using namespace std;\
struct Node{
    int data;
    struct Node *left, *right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left=temp->right=NULL;
    return temp;
}
void postOrder(struct Node* node)  // Left, Right, Root.
{
    if(node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    cout<<node->data<<" ";
}
void inOrder(struct Node* node) // Left, Root, Right.
{
    if(node == NULL)
        return;

    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

void preOrder(struct Node* node) // Root, Left, Right.
{
    if(node == NULL)
        return;

    cout<<node->data<<" ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Pre Order Traversal of binary tree is: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"In Order Traversal of binary tree is: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Post Order Traversal of binary tree is: "<<endl;
    postOrder(root);
    cout<<endl;
}
