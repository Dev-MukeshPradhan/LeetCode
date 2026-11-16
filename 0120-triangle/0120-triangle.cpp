class Solution {
public:
    int helper(vector<vector<int>> &triangle, int i, int j, int m, vector<vector<int>> &dp){
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int d=triangle[i][j]+helper(triangle, i+1, j, m, dp);
        int dr=triangle[i][j]+helper(triangle, i+1, j+1, m, dp);
        dp[i][j]= min(d,dr);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        //int n=triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
        return helper(triangle,0,0,m,dp);
    }
};