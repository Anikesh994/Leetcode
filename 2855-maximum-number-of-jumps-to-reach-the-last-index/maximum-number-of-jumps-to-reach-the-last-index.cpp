class Solution {

int solve(int i ,int j,int n,vector<int>& nums, int target ,vector<vector<int>>&dp ){
    if(i == n - 1){
        if(abs(nums[i] - nums[j]) <= target) return 1;
        return -1e5;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int take=-1e5;
    if(abs(nums[i] - nums[j]) <= target){
        take= 1+ solve(i+1,i,n,nums,target,dp);
    }
    int ntake = solve(i+1,j,n,nums,target,dp);
    return dp[i][j] =max(take,ntake);
}



public:
    int maximumJumps(vector<int>& nums, int target) {
        int n =nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans =solve(1,0,n,nums,target,dp);
        if(ans<0) return -1;
        return ans;

    }
};