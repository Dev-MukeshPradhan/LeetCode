class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> m1; // s
        unordered_map<char,int> m2; // t
        for(int i=0; i<s.size(); i++){
            m1[s[i]]++;
        } 
        for(int i=0; i<t.size(); i++){
            m2[t[i]]++;
        }
        for(auto x : m1){
            char ch1 = x.first;
            int freq1 = x.second;
            if(m2.find(ch1)!=m2.end()){
                int freq2 = m2[ch1];
                if(freq1!=freq2) return false;
            }else{
                return false;
            }

        }
        return true;
    }
};