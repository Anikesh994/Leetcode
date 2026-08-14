class Solution {

int solve(int i , int n ,vector<int>& stoneValue,vector<int>&dp ){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=INT_MIN) return dp[i];
    int best=INT_MIN;
    for(int k=0;k<3 && i+k < n ;k++){
        int res = stoneValue[i] - stoneValue[i+k+1] - solve(i+k+1 ,n ,stoneValue,dp);
        best = max(best ,res);
    }

    return dp[i] = best;
}


public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n+1, INT_MIN);
        for(int i=n-2;i>=0;i--){
            stoneValue[i]+=stoneValue[i+1];
        }
        stoneValue.push_back(0);
        int x =solve(0,n,stoneValue,dp);
        if(x>0) return "Alice";
        else if( x==0) return "Tie";
        return "Bob";
    }
};