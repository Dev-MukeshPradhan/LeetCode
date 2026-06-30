class Solution {
public:
    int mySqrt(int x) {
        // 
        
        int start=0, end=x;
        int mid;
        int ans;

        while(start<=end){
            mid=start+(end-start)/2;
            if((long long)mid*mid==x){
                ans=mid;
                return ans;
            }else if((long long)mid*mid<x){
                start=mid+1;
                ans=mid;
            }else{
                end=mid-1;
            }
        }
        return ans;
        
    }
};