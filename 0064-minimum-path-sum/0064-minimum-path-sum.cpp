class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> prev(n,0);
        for(int i=0; i<m; i++){
            vector<int> curr(n,0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    curr[j]=grid[0][0];
                }
                else{
                    int right=INT_MAX, down=INT_MAX;
                    if(i>0) down=grid[i][j] + prev[j];
                    if(j>0) right=grid[i][j] + curr[j-1];
                    curr[j]=min(down,right);
                }
            }
            prev=curr;
        }
        return prev[n-1];
        
        
    }
};