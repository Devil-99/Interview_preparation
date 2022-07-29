// Partial Code

ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=NULL;
        ListNode* present=head;
        ListNode* start=NULL;
        ListNode* end=NULL;
        int c=1;
        if(right==left)
            return head;
        while(present->next && c<left){
            c++;
            prev=present;
            present=present->next;
        }
        if(c==left){
            start=prev;
            end=present;
            prev=present;
            present=present->next;
            c++;
        }
        ListNode* nxt;
        while(present && c<=right){
            nxt=present->next;
            present->next=prev;
            prev=present;
            present=nxt;
            c++;
        }
        end->next=present;
        if(left==1)
            head=prev;
        else
            start->next=prev;
        return head;
    }