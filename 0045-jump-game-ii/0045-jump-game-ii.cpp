class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int r=0;
        int jumps=0;
        while(r<n-1){
            int far=0;
            for(int j=i; j<=r; j++){
                far=max(far,j+nums[j]);
            }
            jumps++;
            i=r+1;
            r=far;
            
        }
        return jumps;
        
    }
};