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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* first=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        ListNode* second=reverseList(b);
        ListNode* c=new ListNode(0);
        ListNode* tempC=c;
        while(first!=NULL && second!=NULL){
            tempC->next=first;
            first=first->next;
            tempC=tempC->next;
            tempC->next=second;
            second=second->next;
            tempC=tempC->next;
        }
        // Attach remaining nodes
        if (first != NULL)
            tempC->next = first;
        else
            tempC->next = second;
        
    }
};