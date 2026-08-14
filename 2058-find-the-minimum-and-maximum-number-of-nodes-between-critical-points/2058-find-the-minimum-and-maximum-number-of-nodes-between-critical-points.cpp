class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=2;
        int fidx=-1;
        int sidx=-1;
        vector<int>ans(2,-1);
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;
        while(c!=NULL){
            if(a->val>b->val && b->val<c->val || a->val<b->val && b->val>c->val){// checking for citical points
                if(fidx==-1){
                    fidx=idx;
                }else{
                    sidx=idx;
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;

        }
        if(sidx==-1) return ans;
        int maxd=sidx-fidx;
        // now we write code to find min distance
        idx=2;
        fidx=-1;
        sidx=-1;
        int mind;
        a=head;
        b=head->next;
        c=head->next->next;
        while(c!=NULL){
            if(a->val>b->val && b->val<c->val || a->val<b->val && b->val>c->val){// checking for local minima
                if(fidx==-1){
                    fidx=idx;
                }else{
                    sidx=idx;
                    mind=min(mind,sidx-fidx);
                    fidx=sidx;
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;

        }
        if(sidx==-1) return ans;
        if(mind && maxd){
            ans[0]=mind;
            ans[1]=maxd;
        }
        return ans;
        
        
    }
};