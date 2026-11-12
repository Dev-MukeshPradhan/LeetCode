class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp) {   
        // out of boundary
        if(m<0 || n<0) return 0;
        // obstacle encountered
        if (obstacleGrid[m][n] == 1) {
            return 0;
        }
        // if we are able to reach starting cell, the only valid case
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int up = helper(obstacleGrid, m - 1, n, dp);
        int left = helper(obstacleGrid, m, n - 1, dp);
        dp[m][n]= up + left;
        return dp[m][n];


    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, m-1, n-1, dp);
    }
};