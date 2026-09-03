class Solution {
public:
    void helper(vector<int>& nums,
                vector<int>& ans,
                vector<vector<int>>& finalAns,
                int idx) {

        // Base case
        if (idx == nums.size()) {
            finalAns.push_back(ans);
            return;
        }

        // Take nums[idx]
        ans.push_back(nums[idx]);
        helper(nums, ans, finalAns, idx + 1);

        // Undo the choice
        ans.pop_back();

        // Don't take nums[idx]
        helper(nums, ans, finalAns, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;

        helper(nums, ans, finalAns, 0);

        return finalAns;
    }
};

