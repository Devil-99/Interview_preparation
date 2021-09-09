#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        right=left=NULL;
    }
};

void Inorder(Node *root)
{
    if(root==NULL)
    return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node *root)
{
    if(root==NULL)
    return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node *root=new Node(11);
    root->left=new Node(21);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->right->left=new Node(33);
    root->right->right=new Node(34);
    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
    return 0;
}