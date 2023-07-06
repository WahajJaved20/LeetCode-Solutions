class MinStack {
private:
    int findMinimum(){
        int mini = INT_MAX;
        for(int i=0;i<st.size();i++){
            mini = min(mini,st[i]);
        }
        return mini;
    }
public:
    vector<int> st;
    MinStack() {
    }
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        return findMinimum();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
