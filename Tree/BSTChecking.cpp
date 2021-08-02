#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
Node *newNode(int k)
{
    Node *temp=new Node;
    temp->data=k;
    temp->left=temp->right=NULL;
    return temp;
}
bool BSTUtil(Node* node,int min,int max)
    {
        if(node==NULL)
        return true;
        
        if(node->data<=min || node->data>=max)
        return false;
        
        //cout<<min<<" "<<node->data<<" "<<max<<endl;
        return BSTUtil(node->left,min,node->data) && BSTUtil(node->right,node->data,max);
    }
bool isBST(Node* root) 
    {
        return BSTUtil(root,INT_MIN,INT_MAX);
    }

void inorder(Node* root,vector<int> &arr)
    {
        if(root)
        {
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
        }
    }

int main()
{
    Node *root=newNode(4);
    root->left=newNode(2);
    root->right=newNode(5);
    root->left->left=newNode(1);
    root->left->right=newNode(3);
    // root->right->left=newNode(6);
    // root->right->right=newNode(7);
    vector<int> ans;

    inorder(root,ans);
    bool f=1;
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i-1]>ans[i])
        {f=0;
        break;}
    }
    cout<<f<<endl;
    // for(auto i:ans)
    // cout<<i<<" ";
    // cout<<endl;
    //cout<<isBST(root);
return 0;
}