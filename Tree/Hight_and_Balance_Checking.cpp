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

int height(Node *root)
{
    if(root==NULL)
    return 0;
    else
    {
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
    }
}
bool balanced(Node *root)
{
    int left=height(root->left);
    int right=height(root->right);
    if(abs(right-left)>1)
    return false;
    else
    return true;
}
int main()
{
    Node *root=new Node(11);
    root->left=new Node(21);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(32);
    root->right->left=new Node(33);
    root->right->right=new Node(34);

    (balanced(root))?cout<<"Yes":cout<<"No";
}
