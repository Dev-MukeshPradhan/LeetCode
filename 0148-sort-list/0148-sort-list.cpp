class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* ta=list1;
        ListNode* tb=list2;
        ListNode* c = new ListNode(10);
        ListNode* tc=c;
        while(ta!=NULL && tb!=NULL){
            if(ta->val <= tb->val){
                tc->next=ta;
                ta=ta->next;
                tc=tc->next;

            }else{
                tc->next=tb;
                tb=tb->next;
                tc=tc->next;

            }
        }

        if(ta==NULL){
            tc->next=tb;
        }else{
            tc->next=ta;
        }
        return c->next;
        
    }


    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){  // for reaching slow pointer to middle left
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        ListNode* c = merge(a,b);  
        return c; 
    }
};