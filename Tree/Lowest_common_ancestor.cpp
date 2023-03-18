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

bool recursivePathFind(Node *root,vector<int>&path,int k)
{
    if(root==NULL)
    return false;

    path.push_back(root->data);
    if(root->data==k)
    return true;

    if((root->left && recursivePathFind(root->left,path,k))||(root->right && recursivePathFind(root->right,path,k)))
    return true;

    path.pop_back();
    return false;
}

vector<int> iterativePathFind(Node* root, int k){
    stack<pair<Node*,vector<int>>>st;
    vector<int>v;
    st.push({root,v});
    while(!st.empty()){
        Node* node=st.top().first;
        vector<int>temp=st.top().second;
        st.pop();
        temp.push_back(node->data);
        if(node->data==k)
            return temp;
        if(node->left) st.push({node->left,temp});
        if(node->right) st.push({node->right,temp});
    }
    return v;
}

int ancestor(Node *root,int n1,int n2)
{
    vector<int> path1,path2;
    // recursivePathFind(root,path1,n1);
    // recursivePathFind(root,path2,n2);
    path1=iterativePathFind(root,n1);
    path2=iterativePathFind(root,n2);

    for(int i=0;i<path1.size()&&i<path2.size();i++)
    if(path1[i]!=path2[i])
        return path1[i-1];
    return -1;
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

    int n1=4,n2=5;
    int x=ancestor(root,n1,n2);
    cout<<x<<endl;
    return 0;
}