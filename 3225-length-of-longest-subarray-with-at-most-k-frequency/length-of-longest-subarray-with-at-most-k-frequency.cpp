class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n =nums.size();
        int high=0;
        int low=0;
        int temp=0;
        unordered_map<int,int>um;
        while(high <n){
            um[nums[high]]++;
            
            
            while(um[nums[high]]>k){
                um[nums[low]]--;
                if(um[nums[low]]==0) um.erase(nums[low]);
                low++;
            }
            high++;
            temp = max(temp,high-low);
        }
        return temp;
    }
};