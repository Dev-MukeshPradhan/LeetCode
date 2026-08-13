class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Finding the length of linkedlist
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }

        // splitting into k equal parts
        vector<ListNode*> ans;
        temp=head;
        int sizeToBeSplitted=n/k;
        int rem = n%k;
        while(temp!=NULL){
            ListNode* c=new ListNode(100);
            ListNode* tempC=c;
            int s=sizeToBeSplitted;
            if(rem>0){
                s++;
                rem--;
            }
            for(int i=1; i<=s; i++){ // Jitne ka size banana hai utni baar aage chalo
                tempC->next=temp;
                temp=temp->next;
                tempC=tempC->next;
            }
            tempC->next=NULL;// break the list
            ans.push_back(c->next);
        }

        if(ans.size()<k){
            int diff=k-ans.size();
            for(int i=1; i<=diff; i++){
            ans.push_back(NULL);
            }
        }
        
        return ans;
        
    }
};