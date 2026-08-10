class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo= new ListNode(0);
        ListNode* templ=lo;
        ListNode* hi= new ListNode(1);
        ListNode* temph=hi;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                templ->next=temp;
                temp=temp->next;
                templ=templ->next;
            }else{
                temph->next=temp;
                temp=temp->next;
                temph=temph->next;
            }
        }
        templ->next=NULL;
        temph->next=NULL;

        hi=hi->next;
        templ->next=hi;

        return lo->next;
        
    }
};