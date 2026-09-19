class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int req = target - nums[i];
            if(m.find(req)!=m.end()){
                ans.push_back(m[req]);
                ans.push_back(i);
            }else{
                m[nums[i]]=i;
                
            }
        }
        return ans;
    }
};