class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start=1, ball, sit, mf, ans, mid;
        int n=position.size();
        int end=position[n-1]-position[0];

        while(start<=end){
            mid=start+(end-start)/2;
            ball=1;
            sit=position[0];
            for(int y=1; y<n; y++){
                if(sit+mid<=position[y]){
                    ball++;
                    sit=position[y]; 
                }

            }
            if(ball<m){
                //ans=mid;
                end=mid-1;
            }else{
                ans=mid;
                start=mid+1;
            }
            
        }
        return ans;
        
    }
};