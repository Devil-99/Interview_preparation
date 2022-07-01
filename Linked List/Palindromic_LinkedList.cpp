#include <bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
        int val;
        ListNode *next;

        ListNode(int data)
        {
            val=data;
            next=NULL;
        }
};
bool isPalindrome(ListNode* head) {
        ListNode *slow,*fast;
        slow=head;
        fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=NULL;
        ListNode *cur=slow->next;
        ListNode *post;
        while(cur)
        {
            post=cur->next;
            cur->next=prev;
            prev=cur;
            cur=post;
        }
        slow->next=prev;
        slow=slow->next;
        ListNode *start=head;
        while(slow)
        {
            if(start->val!=slow->val)
                return false;
            start=start->next;
            slow=slow->next;
        }
        return true;
    }

int main() {
    ListNode *root=new ListNode(1);
    root->next=new ListNode(2);
    root->next->next=new ListNode(2);
    root->next->next->next=new ListNode(3);

    if(isPalindrome(root))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}