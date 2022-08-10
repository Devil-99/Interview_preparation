#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(){
        left=NULL;
        right=NULL;
    }
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void mirror(Node* root)
{
    if(root==NULL)
    return;
    mirror(root->left);
    mirror(root->right);

    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
void Inorder(Node *root)
{
    if(root==NULL)
    return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main() {
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);

    mirror(root);
    Inorder(root);
    return 0;
}