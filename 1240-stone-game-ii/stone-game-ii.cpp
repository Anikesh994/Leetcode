class Solution {

int solve(int i ,int m ,int n,vector<vector<int>>&dp ,vector<int>& piles){
    if(i+2*m >=n) return piles[i];
    if(dp[i][m]!=-1) return dp[i][m];

    int best =0;
    
    for(int k=1;k<=2*m;k++){
        int res = piles[i] - solve(i+k ,max(m,k),n,dp,piles);
        best = max(best , res);
    }
    return dp[i][m]=best;
}


public:
    int stoneGameII(vector<int>& piles) {
        int n  =piles.size();
        for(int i=n-2;i>=0;i--){
            piles[i] += piles[i+1];
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
         return solve(0,1,n,dp,piles);

    }
};