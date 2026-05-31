class Solution {
int solve(int n ,int x1 ,int budget1 ,vector<vector<int>>&dp,vector<int>&adj,vector<vector<int>>& items){
    if(n<0 && budget1>=x1) return budget1/x1 ;
    if(n<0 || budget1==0) return 0 ;
    if(dp[n][budget1]!=-1) return dp[n][budget1];
    int take=INT_MIN;
    int ntake=INT_MIN;
    if(budget1 >= items[n][1]){
        take = 1+adj[n]+solve(n-1,x1 ,budget1-items[n][1] ,dp,adj,items);
    }
    ntake = solve(n-1,x1 ,budget1 ,dp,adj,items);
    return dp[n][budget1] = max(take,ntake);
}



public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int>adj(n,0);
        int x1=INT_MAX;
        for(int i=0;i<n;i++){
            x1=min(x1,items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0) adj[i]++;
            }
        }
        vector<vector<int>>dp(n,vector<int>(budget+1,-1));
        return solve(n-1,x1,budget,dp,adj,items);
        

    }
};