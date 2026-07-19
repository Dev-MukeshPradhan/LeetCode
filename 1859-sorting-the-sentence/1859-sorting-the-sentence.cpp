class Solution {
public:
    string sortSentence(string s) {
        string temp;
        int n=s.size();
        vector<string>ans(10);
        int index=0, count=0;
        while(index<n){
            if(s[index]==' '){
                int pos = temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos]=temp;
                temp.clear();
                count++;
                index++;
            }else{
                temp+=s[index];
                index++;
            }
        }
        int pos = temp[temp.size()-1]-'0'; // for the last word of the string s
        temp.pop_back();
        ans[pos]=temp;
        temp.clear();
        count++;

        for(int i=1; i<=count; i++){  // 1-indexed mentioned in the question
            temp+=ans[i];
            temp+=' ';
        }
        temp.pop_back();
        return temp;
        
    }
};