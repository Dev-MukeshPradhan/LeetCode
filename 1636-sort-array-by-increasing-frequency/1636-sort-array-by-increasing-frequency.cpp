class Solution {
public:
    typedef pair<int,int> pi;

    struct comp {
        bool operator()(pi a, pi b) {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<int> frequencySort(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int ele : arr)
            mp[ele]++;

        priority_queue<pi, vector<pi>, comp> pq;

        for(auto x : mp)
            pq.push({x.second, x.first});

        vector<int> ans;

        while(!pq.empty()) {
            int freq = pq.top().first;
            int ele = pq.top().second;
            pq.pop();

            for(int i = 0; i < freq; i++)
                ans.push_back(ele);
        }

        return ans;
    }
};