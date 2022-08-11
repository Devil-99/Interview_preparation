#include<bits/stdc++.h>
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
    Node *root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    // root->right->left=newNode(6);
    // root->right->right=newNode(7);
    vector<int> ans;

    // Iterative Approach
    inorder(root,ans);
    bool f=1;
    for(int i=1;i<ans.size();i++)
    {
        if(ans[i-1]>ans[i])
        {f=0;
        break;}
    }
    cout<<f<<endl;

    // Recursive Approach
    // for(auto i:ans)
    // cout<<i<<" ";
    // cout<<endl;
    //cout<<isBST(root);
    
return 0;
}