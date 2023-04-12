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
Node* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postEnd)
    {
        if (inStart > inEnd || postEnd < 0) {
            return nullptr;
        }
        
        Node* root = new Node(postorder[postEnd]);
        
        int inIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->data) {
                inIndex = i;
                break;
            }
        }
        
        root->right = build(inorder, postorder, inIndex + 1, inEnd, postEnd - 1);
        root->left = build(inorder, postorder, inStart, inIndex - 1, postEnd - (inEnd - inIndex) - 1);
        
        return root;
    }
int main() {
    vector<int> postorder={9,15,7,20,3};
    vector<int> inorder={9,3,15,20,7};
    map<int,int> indexing;
    for(int i=0;i<inorder.size();i++)
        indexing[inorder[i]]=i;
    
    Node* root=build(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    printQueue(root);
    return 0;
}