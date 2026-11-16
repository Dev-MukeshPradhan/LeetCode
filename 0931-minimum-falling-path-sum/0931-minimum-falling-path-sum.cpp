class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n);
        vector<int> curr(n);

        for(int j = 0; j < n; j++){
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){

                int dn = matrix[i][j] + prev[j];

                int dnl = matrix[i][j];
                if(j > 0)
                    dnl += prev[j-1];
                else
                    dnl = 1e8;

                int dnr = matrix[i][j];
                if(j < n-1)
                    dnr += prev[j+1];
                else
                    dnr = 1e8;

                curr[j] = min(dn, min(dnl, dnr));
            }
            prev=curr;
        }

        int mini = 1e8;

        for(int j = 0; j < n; j++){
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};