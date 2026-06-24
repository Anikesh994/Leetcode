class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int i=1;
        dq.push_back(nums[0]);
        vector<int>ans;
        while(i<k){
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            i++;
        }
        int low=0;
        int high =k;
        ans.push_back(dq.front());
        while(!dq.empty() && high<nums.size()){
            if(nums[low]==dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && nums[high]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[high]);
            ans.push_back(dq.front());
            low++;
            high++;
        }
        
        return ans;
    }
    
};