class Solution {
public:
    // int helper(vector<vector<int>>& obstacleGrid, int m, int n,
    // vector<vector<int>>& dp) {
    //     // out of boundary
    //     if(m<0 || n<0) return 0;
    //     // obstacle encountered
    //     if (obstacleGrid[m][n] == 1) {
    //         return 0;
    //     }
    //     // if we are able to reach starting cell, the only valid case
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     if(m==0 && n==0) return 1;

    //     int up = helper(obstacleGrid, m - 1, n, dp);
    //     int left = helper(obstacleGrid, m, n - 1, dp);
    //     dp[m][n]= up + left;
    //     return dp[m][n];
    //}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    } else {
                        int down = 0, right = 0;
                        if (i > 0)
                            down = dp[i - 1][j];
                        if (j > 0)
                            right = dp[i][j - 1];
                        dp[i][j] = down + right;
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};