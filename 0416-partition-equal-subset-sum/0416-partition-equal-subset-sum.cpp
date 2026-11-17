class Solution {
public:
    bool helper(vector<int>& nums, int idx, int tgt, vector<vector<int>>& dp){
        if(tgt==0) return true;
        if(idx==0){
            return nums[0]==tgt;
        }

        if(dp[idx][tgt]!=-1) return dp[idx][tgt];

        bool nopick=helper(nums,idx-1,tgt,dp);
        bool pick=false;
        if(tgt>=nums[idx]){
            pick=helper(nums,idx-1,tgt-nums[idx],dp);
        }

        dp[idx][tgt] = nopick | pick;
        return dp[idx][tgt];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tSum=0;
        
        for(int i=0; i<n; i++){
            tSum+=nums[i];
        }

        vector<vector<int>> dp(n, vector<int>(((tSum+2)/2), -1));

        if(tSum%2!=0){
            return false;
        }
        else{
            return helper(nums,n-1,tSum/2, dp);
        }
        
    }
};