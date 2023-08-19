#include <iostream>
#include <queue>
#include <map>
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

void leftView(Node* root, int level, vector<int>& ans){
    if(!root)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    leftView(root->left,level+1,ans);
    leftView(root->right,level+1,ans);
}

void bottomView(Node *root)
{
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    int level=0;

    if(root==NULL)
    return;

    q.push({root,level});
    while(!q.empty())
    {
        Node *temp=q.front().first;
        int level=q.front().second;
        mp[level]=temp->data;
        q.pop();
        if(temp->left!=NULL)
        q.push({temp->left,level-1});
        if(temp->right!=NULL)
        q.push({temp->right,level+1});
    }
    for(auto it:mp)
        cout<<it.second<<" ";
    cout<<endl;
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
    root->left->right->left=new Node(43);
    root->left->right->right=new Node(44);

    bottomView(root);

    vector<int>ans;
    leftView(root,0,ans);

    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    
    return 0;
}