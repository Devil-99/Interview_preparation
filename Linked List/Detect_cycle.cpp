#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(){
        next=NULL;
    }
    Node(int val){
        data=val;
        next=NULL;
    }
};

bool DetectCycle(Node* head){
    Node *slow=head,*fast=head->next;
    while(fast and slow!=fast){
        slow=slow->next;
        if(fast->next!=NULL)
            fast=fast->next->next;
        else{
            fast=fast->next;
            break;}
    }
    if (fast==NULL)
        return false;
    else{
        Node *start=head;
        slow=slow->next;
        while(start!=slow){
            start=start->next;
            slow=slow->next;
        }
        cout<<"The head of the cycle is "<<start->data<<endl;
        return true;
    }
}

int main()
{
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=head->next;
    // head->next->next->next->next=NULL          // This is for "No" output

    if(DetectCycle(head))
        cout<<"Yes"<<endl;
    else
        cout<<"No";
    return 0;
}