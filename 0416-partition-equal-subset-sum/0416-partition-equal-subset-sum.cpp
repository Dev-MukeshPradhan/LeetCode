class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        // Tabulation
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {

                bool notPick = dp[i-1][t];

                bool pick = false;
                if (t >= nums[i]) {
                    pick = dp[i-1][t - nums[i]];
                }

                dp[i][t] = pick || notPick;
            }
        }

        return dp[n-1][target];
    }
};