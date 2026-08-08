class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL ){ // interchanging them will show runtimr error
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                return true;
            }
            
            
        }
        
        return false;
    }
};