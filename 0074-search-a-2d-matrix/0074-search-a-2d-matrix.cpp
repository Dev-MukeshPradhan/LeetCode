class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0, end=row*col-1;
        while(start<=end){
            int mid = (start+end)/2;
            int r_idx=mid/col;
            int col_idx=mid%col;
            if(matrix[r_idx][col_idx]==target){
                return true;
            }
            else if(matrix[r_idx][col_idx]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return false;
        
    }
};