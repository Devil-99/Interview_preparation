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

bool util(Node* left,Node* right)
    {
        if(left==NULL || right==NULL)
            return right==left;
        if(left->data!=right->data)
            return false;
        return util(left->left,right->right) && util(left->right,right->left);
    }
bool isSymmetric(Node* root) {
    if(root==NULL)
        return true;
    return util(root->left,root->right);
}
int main() {
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(20);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(50);
    root->right->right=new Node(40);

    cout<<isSymmetric(root);
    return 0;
}