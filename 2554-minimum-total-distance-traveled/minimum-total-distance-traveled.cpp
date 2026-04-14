class Solution {

long long solve(int i ,int j,int n,int m ,vector<int>&robot , vector<long long>&factory ,vector<vector<long long>>&dp){
    if(i>=n) return 0;
    if(j>=m) return 1e13;
    if(dp[i][j]!=-1) return dp[i][j];
    long long pick = (long long)abs(factory[j] - (long long)robot[i]) + solve(i+1,j+1,n,m,robot,factory,dp);
    long long npick = solve(i,j+1,n,m,robot,factory,dp);

    return dp[i][j]= min(pick,npick);
}



public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<long long>temp;
        for(int i=0;i<factory.size();i++){
            for(int j=0;j<factory[i][1];j++){
                temp.push_back(factory[i][0]);
            }
        }
        int n = robot.size();
        int m =temp.size();
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        return solve(0,0,n,m,robot,temp,dp);
    }
};