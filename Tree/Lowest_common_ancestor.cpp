# include <bits/stdc++.h>
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

    for(int i=0;i<path1.size()&&i<path2.size();i++)
    if(path1[i]!=path2[i])
    return path1[i-1];
}
int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    int n1,n2;
    cin>>n1>>n2;
    int x=ancestor(root,n1,n2);
    cout<<x<<endl;
    return 0;
}