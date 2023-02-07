#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(){
        next=NULL;
    }
    Node(int val){
        data=val;
        next=NULL;
    }
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

int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=NULL;

    Node* node=head;
    while(node && node->next){
        swap(node->data,node->next->data);
        node=node->next->next;
    }
    print(head);
    return 0;
}