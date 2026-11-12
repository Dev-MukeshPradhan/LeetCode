class Solution {
public:
    // int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
    //     if(m==0 && n==0) return grid[m][n];
    //     if(m<0 || n<0) return INT_MAX;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int up=helper(grid, m-1, n, dp);
    //     int left=helper(grid, m, n-1, dp);
    //     if(up!=INT_MAX){
    //         up+=grid[m][n];
    //     }
    //     if(left!=INT_MAX){
    //         left+=grid[m][n];
    //     }
    //     dp[m][n]=min(up,left);
    //     return dp[m][n];
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[0][0];
                }else{
                    int right=INT_MAX, down=INT_MAX;
                    if(i>0) down=grid[i][j] + dp[i-1][j];
                    if(j>0) right=grid[i][j] + dp[i][j-1];
                    dp[i][j]=min(down,right);
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};