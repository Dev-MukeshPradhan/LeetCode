class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag = false; // Repreents no cycle in linkedlist
        while(fast!=NULL && fast->next!=NULL ){ // interchanging them will show runtimr error
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                flag=true;
                break;
            }
            
        }
        if(flag==false){
            return NULL;
        }else{
            ListNode* temp=head;
            while(temp!=slow){
                temp=temp->next;
                slow=slow->next;
            }
        }

        return slow;
        
    }
};