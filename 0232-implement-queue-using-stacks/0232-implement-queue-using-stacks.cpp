class MyQueue {
public:
    stack<int> st;
    stack<int> hp;
    MyQueue() {  
    }
    void push(int x) { // O(1)
        st.push(x);
    }
    int pop() { //O(n)
        // remove at bottom
        while(st.size()>0){
            hp.push(st.top());
            st.pop();
        }
        int x=hp.top();
        hp.pop();
        while(hp.size()>0){
            st.push(hp.top());
            hp.pop();
        }
        return x;
        
    }
    int peek() {
        // retrieve at bottom
        while(st.size()>0){
            hp.push(st.top());
            st.pop();
        }
        int x=hp.top();
        while(hp.size()>0){
            st.push(hp.top());
            hp.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size()==0) return true;
        else return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */