class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int> dp(m);

        // initialise with the last row
        for(int j=0; j<m; j++){
            dp[j]=triangle[m-1][j];
        }

        // Bottom up DP
        for(int i=m-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                // dp[j] and dp[j+1] cointains the old value over which we will overwritte them
                // int up=triangle[i][j]+dp[j];
                // int upl=triangle[i][j]+dp[j+1];
                // curr[j]=min(up,upl);
                // OR
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
                // dp[j] and dp[j+1] cointains the old value over which we have overwritten dp[j] and next we will overrite dp[j+1] too
            }
        }
        return dp[0];
    }
};