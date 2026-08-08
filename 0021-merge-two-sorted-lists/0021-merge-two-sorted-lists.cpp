class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};