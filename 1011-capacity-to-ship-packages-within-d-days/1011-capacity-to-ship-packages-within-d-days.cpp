class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int mid, ans;
        int n=weights.size();

        while(start<=end){
            mid=start+(end-start)/2;
            int load=0;
            int req_days = 1;
            for(int i=0; i<n; i++){
                load=load+weights[i];
                if(load>mid){
                    req_days++;
                    load=weights[i];
                }
            }
            if(req_days<=days){
                    ans=mid;
                    end=mid-1;
                }else{
                    start=mid+1;
                } 
        }
        return ans;   
    }
};