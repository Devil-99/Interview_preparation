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

int count(Node* node,int mx){
    if(node==NULL) return 0;
    if(node->data<mx)
    return count(node->left,mx)+count(node->right,mx);

    return 1+count(node->left,node->data)+count(node->right,node->data);
}

int main() {
    Node *root=new Node(3);
    root->left=new Node(1);
    root->right=new Node(4);
    root->left->left=new Node(3);
    root->right->left=new Node(1);
    root->right->right=new Node(5);

    int mx= INT_MIN;

    cout<<count(root,mx)<<endl;
    return 0;
}