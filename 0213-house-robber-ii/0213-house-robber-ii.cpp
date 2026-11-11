class Solution {
public:
    int helper(vector<int>&nums, int start, int end){
        int n=nums.size();
        if(start==end) return nums[start];
        int prev1=nums[start];
        int prev2=max(nums[start], nums[start+1]); 
        
        for(int i=start+2; i<=end; i++){
            int pick=nums[i]+prev1;
            int nopick=prev2;
            int curr=max(pick,nopick);
            prev1=prev2;
            prev2=curr;
        }

        return prev2;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int case1=helper(nums,0,n-2);
        int case2=helper(nums,1,n-1);
        return max(case1,case2);
    }
};