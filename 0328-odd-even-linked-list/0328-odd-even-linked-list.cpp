class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=new ListNode(0);
        ListNode* oddt=odd;
        ListNode* even=new ListNode(1);
        ListNode* event=even;
        ListNode* temp=head;
        int count=1;
        while(temp!=NULL){
            if(count%2!=0){
                oddt->next=temp;
                oddt=oddt->next;
                temp=temp->next;
                count++;
            }else{
                event->next=temp;
                event=event->next;
                temp=temp->next;
                count++;
            }
            
        }
        oddt->next=NULL;
        event->next=NULL;

        even=even->next;
        oddt->next=even;

        return odd->next;
        
    }
};