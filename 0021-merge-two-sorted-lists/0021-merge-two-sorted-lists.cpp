class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ta=list1;
        ListNode* tb=list2;
        ListNode* c = new ListNode(10);
        ListNode* tc=c;
        while(ta!=NULL && tb!=NULL){
            if(ta->val >= tb->val){
                ListNode* t = new ListNode(tb->val);
                tc->next=t;  // you should have a node to add to next node of new linkedList C
                tc=t;
                tb=tb->next;
            }else{
                ListNode* t = new ListNode(ta->val);
                tc->next=t;  // you should have a node to add to next node of new linkedList C
                tc=t;
                ta=ta->next;

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