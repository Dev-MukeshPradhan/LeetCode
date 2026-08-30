class Solution {
public:

    void solve(int idx, vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Every temp is a valid subset
        ans.push_back(temp);

        // Try every element from idx onwards
        for(int i = idx; i < nums.size(); i++) {

            // Choose
            temp.push_back(nums[i]);

            // Move to next element
            solve(i + 1, nums, temp, ans);

            // Undo choice
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};