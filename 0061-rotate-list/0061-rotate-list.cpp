class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next==NULL || k==0){
            return head;
        }
        int len=0;
        ListNode* temp=head;
        ListNode* tail=NULL;
        while(temp!=NULL){
            len++;
            if(temp->next==NULL){
                tail=temp;
            }
            temp=temp->next;
        }
        k=k%len;
        
        temp=head;
        for(int i=1; i<len-k; i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;

        return head;
    }
};