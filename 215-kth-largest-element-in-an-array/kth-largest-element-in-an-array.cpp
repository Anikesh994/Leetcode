class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n =nums.size();
        priority_queue<int, vector<int>> minHeap;
        for(int i=0;i<n;i++){
            minHeap.push(nums[i]);
        }
        int i=0;
        while(i<k-1){
            minHeap.pop();
            i++;
        }
        return minHeap.top();
    }
};