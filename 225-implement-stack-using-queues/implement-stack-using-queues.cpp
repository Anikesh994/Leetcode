class MyStack {
public:
    queue<int>qt;
    MyStack() {
        
    }
    
    void push(int x) {
        int n=qt.size();
        qt.push(x);
        for(int i=0;i<n;i++){
            int x1= qt.front();
            qt.pop();
            qt.push(x1);
        }
    }
    
    int pop() {
        int x =qt.front();
        qt.pop();
        return x;

    }
    
    int top() {
        return qt.front();
    }
    
    bool empty() {
        return qt.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */