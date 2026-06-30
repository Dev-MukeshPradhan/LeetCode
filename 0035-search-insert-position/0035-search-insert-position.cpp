class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, index, mid;

        while(start<=end){
            mid=start+(end-start)/2;
            if(nums[mid]==target){
                index=mid;
                return index;
            }else if(nums[mid]>target){
                end=mid-1;
                index=mid;
            }else{
                start=mid+1;
                index=mid+1;
            }
        }
        return index;
        
    }
};