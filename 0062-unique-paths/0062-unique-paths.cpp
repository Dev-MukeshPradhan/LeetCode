class Solution {
public:
    // int helper(int m, int n, vector<vector<int>> &dp){
    //     // out of boundary
    //     if(m<0 || n<0){
    //         return 0;
    //     }
    //     // starting cell
    //     if(m==0 || n==0) return 1;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int up=helper(m-1,n, dp);
    //     int left=helper(m,n-1, dp);
    //     dp[m][n] = up+left;
    //     return dp[m][n];
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    int down = 0, right = 0;

                    if(i>0) down=dp[i-1][j];
                    if(j>0) right=dp[i][j-1];

                    dp[i][j]=down+right;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};