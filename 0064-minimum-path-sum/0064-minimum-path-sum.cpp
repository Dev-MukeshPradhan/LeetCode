class Solution {
public:
    int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        if(m==0 && n==0) return grid[m][n];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=helper(grid, m-1, n, dp);
        int left=helper(grid, m, n-1, dp);
        if(up!=INT_MAX){
            up+=grid[m][n];
        }
        if(left!=INT_MAX){
            left+=grid[m][n];
        }
        dp[m][n]=min(up,left);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(grid, m-1, n-1, dp);
        
    }
};