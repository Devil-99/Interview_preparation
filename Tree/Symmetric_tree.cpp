#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode *left,*right;
    TreeNode(int data)
    {
        val=data;
        right=left=NULL;
    }
};
bool util(TreeNode* left,TreeNode* right)
    {
        if(left==NULL || right==NULL)
            return right==left;
        if(left->val!=right->val)
            return false;
        return util(left->left,right->right) && util(left->right,right->left);
    }
bool isSymmetric(TreeNode* root) {
    if(root==NULL)
        return true;
    return util(root->left,root->right);
}
int main() {
 TreeNode *root=new TreeNode(10);
    root->left=new TreeNode(20);
    root->right=new TreeNode(20);
    root->left->left=new TreeNode(40);
    root->left->right=new TreeNode(50);
    root->right->left=new TreeNode(50);
    root->right->right=new TreeNode(40);

    cout<<isSymmetric(root);
    return 0;
}