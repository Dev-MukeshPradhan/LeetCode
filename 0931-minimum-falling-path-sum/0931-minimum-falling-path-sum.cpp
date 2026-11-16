class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        // Always keep in mind to put the boundary overflow coditions at the top
        if(i<0 || j<0) return 1e8;
        if(j>matrix.size()-1) return 1e8;
        if(i==0) return matrix[i][j];

        if(dp[i][j]!=1e8) return dp[i][j];
        
        int up=matrix[i][j]+helper(matrix, i-1, j, dp);
        int upl=matrix[i][j]+helper(matrix, i-1, j-1, dp);
        int upr=matrix[i][j]+helper(matrix, i-1, j+1, dp);
        dp[i][j]= min(up, min(upl,upr));
        return dp[i][j];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=1e8;
        vector<vector<int>> dp(n, vector<int>(n, 1e8));
        for(int j=0; j<n; j++){
            mini=min(mini, helper(matrix, n-1, j, dp));
        }
        return mini;
        
    }
};