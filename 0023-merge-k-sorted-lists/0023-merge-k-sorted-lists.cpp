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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        while(lists.size()>1){
            ListNode* a = lists[lists.size()-1];
            lists.pop_back(); // Size of the list is decreased
            ListNode* b = lists[lists.size()-1];
            lists.pop_back(); // Size of the list is decreased
            ListNode* c = merge(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};