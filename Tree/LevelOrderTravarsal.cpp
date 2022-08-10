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

void printRecursive(Node *root,int h)
{
    if(root==NULL || h<1)
    return;
    if(h==1)
    cout<<root->data<<" ";
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

    // Recursive approach
    // int h=height(root);
    // //cout<<h<<endl;
    // for(int i=1;i<=h;i++)
    // printRecursive(root,i);
    
    // Iterative approach
    printQueue(root);
    // (balanced(root))?cout<<"Yes":cout<<"No";
}
