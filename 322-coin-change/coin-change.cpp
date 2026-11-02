class Solution {

int solve(int i,vector<int>& coins, int amount ,vector<vector<int>>&dp){
    if(amount==0) return 0;
    if(i==coins.size()) return INT_MAX;
    if(dp[i][amount]!=-1) return dp[i][amount];

    int pick =INT_MAX;
    if(amount>=coins[i]){
        int res  = solve(i, coins,amount-coins[i],dp);
        if(res !=INT_MAX){
            pick=res+1;
        }
    }
    int npick = solve(i+1,coins,amount,dp);

    return dp[i][amount] = min(pick, npick);
}




public:
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        int ans= solve(0,coins,amount,dp);
        return ans!=INT_MAX ? ans : -1;
    }
};