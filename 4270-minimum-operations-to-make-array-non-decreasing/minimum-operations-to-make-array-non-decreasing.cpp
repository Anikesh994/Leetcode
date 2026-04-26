class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        if(n==1) return 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                ans+=(nums[i]-nums[i+1]);
            }
        }
        return ans;
    }
};