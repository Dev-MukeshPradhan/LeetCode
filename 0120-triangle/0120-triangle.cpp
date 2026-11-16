class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int> prev(m);
        vector<int> curr(m);
        
        for(int j=0; j<m; j++){
            prev[j]=triangle[m-1][j];
        }


        for(int i=m-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                int up=triangle[i][j]+prev[j];
                int upl=triangle[i][j]+prev[j+1];
                curr[j]=min(up,upl);
            }
            prev=curr;
        }
        return prev[0];
    }
};