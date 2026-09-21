class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> m;
        for(int ele : digits) {
            m[ele]++;
        }
        vector<int> ans;
        for(int i = 100; i <= 998; i += 2) {
            int a = i % 10;
            int b = (i / 10) % 10;
            int c = i / 100;

            if(m[c] > 0) {
                m[c]--;
                if(m[b] > 0) {
                    m[b]--;
                    if(m[a] > 0) {
                        ans.push_back(i);
                    }
                    m[b]++;
                }
                m[c]++;
            }
        }
        return ans;
    }
};