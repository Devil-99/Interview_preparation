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

void util(Node *root, int level, vector<int>& ans) {
    if(!root)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    util(root->right,level+1,ans);
    util(root->left,level+1,ans);
}

int main() {
    Node *root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int>ans;
    util(root,0,ans);

    for(auto i:ans)
        cout<<i<<endl;

    return 1;
}