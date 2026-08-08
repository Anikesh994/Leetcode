class KthLargest {

// class cmp{
// public:
//     bool operator()(const int a)
// }

public:
    priority_queue<int, vector<int> , greater<int>>pq;
    int q;
    KthLargest(int k, vector<int>& nums) {
        q=k;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                pq.push(nums[i]);
            }
            else{
                auto it = pq.top();
                
                if(it<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }       
    }
    
    int add(int val) {
        if(pq.size() <q){
            pq.push(val);
            return pq.top();
        }
        auto it = pq.top();
        
        if(it<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */