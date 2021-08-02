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
void printRecursive(Node *root,int h)
{
    if(root==NULL)
    return;
    if(h==1)
    cout<<root->data<<endl;
    else
    {
        printRecursive(root->left,h-1);
        printRecursive(root->right,h-1);
    }
}
void printQueue(Node *root)
{
    queue<Node *> q;
    if(root==NULL)
    return;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        cout<<temp->data<<"  ";
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
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
    // for(int i=1;i<=h;i++)
    // printRecursive(root,i);
    printQueue(root);
}