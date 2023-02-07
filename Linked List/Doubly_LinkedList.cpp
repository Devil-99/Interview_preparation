#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int val,Node* prev){
        data=val;
        left=prev;
        right=NULL;
    }
};

void print(Node *root)
{
    while(root)
    {
        cout<<root->data;
        root=root->right;
        if(root)
        cout<<"->";
    }
    cout<<endl;
}
void revPrint(Node *root)
{
    while(root->right)
    root=root->right;
    while(root)
    {
        cout<<root->data;
        root=root->left;
        if(root)
        cout<<"->";
    }
    cout<<endl;
}

int main(){
    Node *head=new Node(1,NULL);
    head->right=new Node(2,head);
    head->right->right=new Node(3,head->right);
    head->right->right->right=new Node(4,head->right->right);
    head->right->right->right->right=new Node(5,head->right->right->right);

    print(head);
    revPrint(head);
    return 0;
}