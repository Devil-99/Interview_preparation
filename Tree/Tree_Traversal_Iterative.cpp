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

void Inorder(Node *root)
{
    stack<Node*> s;
    s.push(root);
    while(true)
    {
        if(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            if(s.empty())
            break;
            Node* temp=s.top();
            cout<<temp->data<<" ";
            s.pop();
            root=temp->right;
        }
    }
    cout<<endl;
}

void Preorder(Node *root)
{
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node* temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right!=NULL)
        s.push(temp->right);
        if(temp->left!=NULL)
        s.push(temp->left);
    }
    cout<<endl;
}

int main() {
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(7);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->left->right->left=new Node(5);
    root->left->right->right=new Node(6);
    
    Inorder(root);
    Preorder(root);
    // cout<<endl;
    // Postorder(root);
    return 0;
}