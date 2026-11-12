class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    dp[j]=grid[0][0];
                }
                else{
                    int right=INT_MAX, down=INT_MAX;
                    if(i>0) down=grid[i][j] + dp[j];
                    if(j>0) right=grid[i][j] + dp[j-1];
                    dp[j]=min(down,right);
                }
            }
        }
        return dp[n-1];
        
        
    }
};