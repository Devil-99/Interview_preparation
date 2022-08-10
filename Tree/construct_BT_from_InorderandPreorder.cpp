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
Node* util(vector<int> &preorder,int preStart,int preEnd, vector<int> &inorder,int inStart,int inEnd,map<int,int> mp)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        Node* root=new Node(preorder[preStart]);
        int rootIdx=mp[root->data];
        int n=rootIdx-inStart;
        root->left=util(preorder,preStart+1,preStart+n,inorder,inStart,rootIdx-1,mp);
        root->right=util(preorder,preStart+n+1,preEnd,inorder,rootIdx+1,inEnd,mp);
        return root;
    }
int main() {
    vector<int> preorder={3,9,1,2,20,15,7};
    vector<int> inorder={1,9,2,3,15,20,7};
    map<int,int> indexing;
    for(int i=0;i<inorder.size();i++)
        indexing[inorder[i]]=i;
    
    Node* root=util(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,indexing);
    printQueue(root);
    return 0;
}