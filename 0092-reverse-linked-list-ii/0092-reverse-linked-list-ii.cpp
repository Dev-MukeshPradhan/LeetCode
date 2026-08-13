class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right) return head;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL){
            if(count==left-1){
                a=temp;
            }
            if(count==left){
                b=temp;
            }
            if(count==right){
                c=temp;
            }
            if(count==right+1){
                d=temp;
            }
            temp=temp->next;
            count++;
        }

        if(a) a->next=NULL; // if a is not assigned any node beacuse left==1
        c->next=NULL;
        ListNode* newHead=reverseList(b);
        if(a) a->next=newHead;
        b->next=d;

        if(a) return head;
        return c;
    }
};