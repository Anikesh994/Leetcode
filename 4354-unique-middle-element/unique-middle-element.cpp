class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int c=0;
        for(auto it :nums ){
            if(it==nums[n/2]) c++;
            if(c>1) return false;
        }
        if(c>1) return false;
        return true;

    }
};