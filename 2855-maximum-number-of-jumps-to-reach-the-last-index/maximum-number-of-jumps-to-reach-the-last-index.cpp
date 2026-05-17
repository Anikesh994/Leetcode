class Solution {

int solve(int i ,int n,vector<int>& nums, int target ,vector<int>&dp ){

    if(i == n - 1) return 0;
    if(dp[i] != -1) return dp[i];
    int take = -1e5;
    for(int j = i + 1; j < n; j++){
        if(abs(nums[j] - nums[i]) <= target){
            take = max(take, 1 + solve(j, n, nums, target, dp));
        }
    }
    return dp[i] = take;
}

public:
    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = solve(0, n, nums, target, dp);
        if(ans < 0) return -1;
        return ans;
    }
};