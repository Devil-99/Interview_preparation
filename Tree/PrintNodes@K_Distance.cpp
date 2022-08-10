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
    Node *root=new Node(11);
    root->left=new Node(21);
    root->right=new Node(22);
    root->left->left=new Node(31);
    root->left->right=new Node(32);
    root->right->left=new Node(33);
    root->right->right=new Node(34);

    height(root,2,1);

}