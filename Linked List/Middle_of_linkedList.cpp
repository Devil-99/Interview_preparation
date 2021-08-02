#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
void print(Node *root)
{
    while(root)
    {
        cout<<root->data;
        root=root->next;
        if(root)
        cout<<"->";
    }
}

Node* create()
{
    Node *head=NULL;
    Node *node=new Node();
    head=node;
    int n,x;
    cout<<"Enter number of items:-";
    cin>>n;
    cout<<"Enter items:-\n";
    cin>>x;
    node->data=x;
    node->next=NULL;
    while(--n)
    {
        node->next=new Node();
        node=node->next;
        cin>>x;
        node->data=x;
        node->next=NULL;
    }
    return head;
}
int main()
{
    Node *root=create();
    //print(root);
     Node *curr=root;
     Node *post=curr->next->next;
     while(post!=NULL)
     {
         if(post->next==NULL)
         break;
         //cout<<curr->data<<" "<<post->data<<endl;
         curr=curr->next;
         post=post->next->next;
     }
     curr=curr->next;
     cout<<curr->data;
    return 0;
}