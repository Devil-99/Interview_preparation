#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(){
        next=NULL;
    }
    ListNode(int val){
        data=val;
        next=NULL;
    }
};
void print(ListNode *root)
{
    while(root)
    {
        cout<<root->data;
        root=root->next;
        if(root)
        cout<<"->";
    }
}
int length(ListNode* node){
    int count=0;
    while(node){
        count++;
        node = node->next;
    }
    return count;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(length(head)<k)
        return head;
    
    ListNode* curr = head;
    ListNode* next = nullptr;
    ListNode* prev = nullptr;
    for(int i=0; i<k; i++){
            next = curr->next;
            curr->next= prev;
            prev = curr;
            curr = next;
    }
    head -> next = reverseKGroup(curr,k);
    return prev;
}

int main(){
    ListNode* root=new ListNode(1);
    root->next=new ListNode(2);
    root->next->next=new ListNode(3);
    root->next->next->next=new ListNode(4);
    root->next->next->next->next=new ListNode(5);
    int k=2;
    ListNode *head= reverseKGroup(root,k);
    print(head);
    return 0;
}