class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int i=1;
        int ans = 0;

        while((long long)i*i<=x){
            i++;
        }
        ans = i-1;
        return ans;
        
    }
};