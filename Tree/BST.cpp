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

// Insert element in BST
Node *insert(Node* root, int value){
    if(root==NULL)
        return new Node(value);
    
    if(value > root->data)
        root->right = insert(root->right,value);
    if(value < root->data)
        root->left = insert(root->left,value);
    
    return root;
}

// BST Checking
bool checkBST(Node* node,int min,int max)
{
    if(node==NULL)
    return true;
    
    if(node->data<=min || node->data>=max)
    return false;
    
    //cout<<min<<" "<<node->data<<" "<<max<<endl;
    return checkBST(node->left,min,node->data) && checkBST(node->right,node->data,max);
}

// Right and Left view of BST
void rightView(Node* root, int level, int &max_level){
    if (root == NULL)
        return;

    if (max_level < level) {
        cout<< root->data<<endl;
        max_level = level;
    }
  
    rightView(root->right, level + 1,max_level);
    rightView(root->left, level + 1,max_level);

    // for Left view
    // leftViewUtil(root->left, level + 1, max_level);
    // leftViewUtil(root->right, level + 1, max_level);
}

// Delete Node

Node* minValueNode(Node* node){
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

Node* deleteNode(Node *root, int value){
    if(root==NULL)
        return root;
    
    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else{
        if(root->left==NULL && root->right==NULL)
        return NULL;
        else if(root->left==NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Print Inorder
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

    insert(root,6);
    insert(root,7);

    // Print
    vector<int> ans;
    inorder(root,ans);
    for(int a:ans)
        cout<<a<<" ";
    cout<<endl;

    checkBST(root,INT_MIN,INT_MAX)?cout<< "Yes":cout<< "No";
    cout<<endl;

    vector<int>Ans;
    Node *Root = deleteNode(root, 2);
    inorder(root,Ans);
    for(int a:Ans)
        cout<<a<<" ";
    cout<<endl;

    int max_level = 0;
    // rightView(root, 1, max_level);
    
return 0;
}