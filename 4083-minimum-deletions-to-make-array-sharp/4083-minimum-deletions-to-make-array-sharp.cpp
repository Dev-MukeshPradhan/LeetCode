class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int deletions = 0;
        int i =0;
        while(i+1<nums.size()){
            if(nums[i]==nums[i+1]){
                deletions++;
                i+=1;
            }else{
                i++;
            }
        }
        return deletions;
        
    }
};