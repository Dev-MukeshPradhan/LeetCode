class Solution {
public:
    int helper(vector<vector<int>> &grid, int m, int n, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        // handling outflow boundary conditions
        if(j1<0 || j2<0 || j1>n-1 || j2>n-1){
            return -1e8;
        }

        // base case for ending
        if(i==m-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        // Explore alice and bob path simultaneously
        int maxi=-1e8;
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                int value=0;
                if(j1==j2){
                    value=grid[i][j1];
                }
                else{
                    value=grid[i][j1]+grid[i][j2];
                }
                value+=helper(grid, m, n, i+1, dj1+j1, dj2+j2, dp);
                maxi=max(maxi, value);
                dp[i][j1][j2]=maxi;
            }
        }
        return dp[i][j1][j2];

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector[r][j1][j2]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n,-1)));
        return helper(grid, m, n, 0, 0, n-1, dp);
        
    }
};