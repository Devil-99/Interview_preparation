#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
};
Node *newNode(int k)
{
    Node *temp=new Node;
    temp->data=k;
    temp->left=temp->right=NULL;
    return temp;
}
void zigzagRecursive(Node *root,int h,bool lr)
{
    if(root==NULL)
    return;
    if(h==1)
    cout<<root->data<<endl;
    else
    {
        if(lr)
        {
            zigzagRecursive(root->left,h-1,lr);
            zigzagRecursive(root->right,h-1,lr);
        }
        else
        {
            zigzagRecursive(root->right,h-1,lr);
            zigzagRecursive(root->left,h-1,lr);
        }
    }
}

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
int main()
{
    Node *root=newNode(11);
    root->left=newNode(21);
    root->right=newNode(22);
    root->left->left=newNode(31);
    root->left->right=newNode(32);
    root->right->left=newNode(33);
    root->right->right=newNode(34);

    int h=height(root);
    cout<<h<<endl;
    int lr=true;
    for(int i=1;i<=h;i++)
    {
        zigzagRecursive(root,i,lr);
        lr=!lr;
    }
    return 0;
}