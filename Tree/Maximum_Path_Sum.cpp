#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        right=left=NULL;
    }
};

int maxPath(Node *root,int &mx)
{
    if(root==NULL)
    return 0;

    int lsum=max(0,maxPath(root->left,mx));
    int rsum=max(0,maxPath(root->right,mx));
    mx=max(mx,lsum+root->data+rsum);
    return root->data+max(lsum,rsum);
}

int main() {
    Node *root=new Node(15);
    root->left=new Node(10);
    root->right=new Node(20);
    root->right->left=new Node(-30);
    root->right->right=new Node(-15);

    int mx= INT_MIN;
    //maximum sum path (From root to leaf node)
    cout<<maxPath(root,mx)<<endl;
    // maximum sum subtree (From any node to any node)
    cout<<mx;
    return 0;
}