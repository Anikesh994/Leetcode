class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int i=0;
        while(!st.empty() && st.top().first <= price){
            auto x = st.top();
            st.pop();
            i+=x.second;
        }
        st.push({price ,i+1});
        return i+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */