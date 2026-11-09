class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int minC=0;
        int maxC=0;
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                minC++;
                maxC++;
            }
            else if(s[i]==')'){
                minC--;
                maxC--;
            }
            else{
                minC--;
                maxC++;
            }
            if(minC<0){
                minC=0;
            }
            if(maxC<0){
                return false;
            }
        }
        if(min(minC,maxC)==count){
            return true;
        }
        else{
            return false;
        }
        
    }
};