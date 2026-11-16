class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> dp(n);

        for(int j = 0; j < n; j++){
            dp[j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){

            int prevDiagonal = 1e8;

            for(int j = 0; j < n; j++){

                int temp = dp[j];  // Preserve old dp[j]

                int dn = matrix[i][j] + dp[j];

                int dnl = matrix[i][j] + prevDiagonal;

                int dnr = matrix[i][j];

                if(j < n-1)
                    dnr += dp[j+1];
                else
                    dnr = 1e8;

                dp[j] = min(dn, min(dnl, dnr));

                prevDiagonal = temp;
            }
        }

        int mini = 1e8;

        for(int j = 0; j < n; j++){
            mini = min(mini, dp[j]);
        }

        return mini;
    }
};