class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 1e8));

        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){

                int dn = matrix[i][j] + dp[i-1][j];

                int dnl = matrix[i][j];
                if(j > 0)
                    dnl += dp[i-1][j-1];
                else
                    dnl = 1e8;

                int dnr = matrix[i][j];
                if(j < n-1)
                    dnr += dp[i-1][j+1];
                else
                    dnr = 1e8;

                dp[i][j] = min(dn, min(dnl, dnr));
            }
        }

        int mini = 1e8;

        for(int j = 0; j < n; j++){
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};