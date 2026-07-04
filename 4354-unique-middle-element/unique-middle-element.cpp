class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==nums[n/2] && i!= (n/2)) return false;
        }
        return true;

    }
};