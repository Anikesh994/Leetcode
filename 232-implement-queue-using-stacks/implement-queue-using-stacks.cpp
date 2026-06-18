class MyQueue {
public:
stack<int>st,st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        int n =st.size();
        for(int i=0;i<n;i++){
            int x1= st.top();
            st.pop();
            st1.push(x1);
        }
        st.push(x);
        n=st1.size();
        for(int i=0;i<n;i++){
            int x2= st1.top();
            st1.pop();
            st.push(x2);
        }
        
    }
    
    int pop() {
        int x =st.top();
        st.pop();
        return x;

    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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