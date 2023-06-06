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

void printRecursive(Node *root,int h)
{
    if(root==NULL || h<1)
    return;
    if(h==1)
    cout<<root->data<<" ";
    else
    {
        printRecursive(root->left,h-1);
        printRecursive(root->right,h-1);
    }
}
void printQueue(Node *root)
{
    queue<Node *> q;
    if(root==NULL)
    return;
    q.push(root);
    while(!q.empty())
    {
        for(int i=0;i<q.size();i++){
            Node *temp=q.front();
            cout<<temp->data<<"  ";
            q.pop();
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
        cout<<endl;
    }
}

int height(Node *root)
{
    if(root==NULL)
    return 0;
    else
    {
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
    }
}

void avg(Node *root,int h,int &sum,int &c){
    if(root==NULL || h<1)
    return;
    if(h==1){
        sum += root->data;
        c++;
        return;
    }
    else
    {
        avg(root->left,h-1,sum,c);
        avg(root->right,h-1,sum,c);
    }
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

    // int h=height(root);
    //cout<<h<<endl;
    
    // Recursive approach
    // for(int i=1;i<=h;i++)
    // printRecursive(root,i);
    
    // Print avarage for each level
    // for(int i=1;i<=h;i++){
    //     int sum=0,c=0;
    //     avg(root,i,sum,c);
    //     cout<<double(sum)/double(c)<<endl;
    // }

    // Iterative approach
    printQueue(root);
}
