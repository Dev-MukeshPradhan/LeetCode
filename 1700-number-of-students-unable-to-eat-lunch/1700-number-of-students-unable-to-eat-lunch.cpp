class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n=students.size();
        int count=0;
        int j=0;
        for(int i=0; i<n; i++){
            q.push(students[i]);
        }
        while(count<n && sandwiches.size()>j){
            int sdt=q.front();
            if(sdt==sandwiches[j]){
                q.pop();
                j++;
                count=0;
            }else{
                int x=q.front();
                q.pop();
                q.push(x);
                count++;
            }
        }
        return q.size();
        
    }
};