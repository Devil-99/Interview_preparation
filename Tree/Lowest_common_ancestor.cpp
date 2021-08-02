# include <bits/stdc++.h>
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

bool pathFind(Node *root,vector<int>&path,int k)
{
    if(root==NULL)
    return false;

    path.push_back(root->data);
    if(root->data==k)
    return true;

    if((root->left && pathFind(root->left,path,k))||(root->right && pathFind(root->right,path,k)))
    return true;

    path.pop_back();
    return false;
}

int ancestor(Node *root,int n1,int n2)
{
    vector<int> path1,path2;
    pathFind(root,path1,n1);
    pathFind(root,path2,n2);

    // for(auto it1:path1)
    // cout<<it1<<" ";
    // cout<<endl;
    // for(auto it2:path2)
    // cout<<it2<<" ";

    for(int i=0;i<path1.size()&&i<path2.size();i++)
    if(path1[i]!=path2[i])
    return path1[i-1];
}
int main()
{
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    int n1,n2;
    cin>>n1>>n2;
    int x=ancestor(root,n1,n2);
    cout<<x<<endl;
    return 0;
}