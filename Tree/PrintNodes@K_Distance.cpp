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
void height(Node *root,int k,int h)
{
    if(root==NULL)
    {cout<<"None"<<endl;
    return ;}
    else
    {
        if(h==k)
        {cout<<root->data<<endl;
        return;}
        height(root->left,k,h+1);
        height(root->right,k,h+1);
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

    height(root,2,1);

}