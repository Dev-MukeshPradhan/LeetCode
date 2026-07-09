class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l_max[n], r_max[n];
        l_max[0]=0, r_max[n-1]=0;
        int water=0, min_ht=0;

        for(int i=1; i<n; i++){
            l_max[i]=max(l_max[i-1], height[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            r_max[i]=max(r_max[i+1], height[i+1]);
        }
        for(int i=0; i<n; i++){
            min_ht=min(l_max[i], r_max[i]);
            if(min_ht-height[i]>=0){
                water=water+min_ht-height[i];
            }
        }
        return water;
    }
};