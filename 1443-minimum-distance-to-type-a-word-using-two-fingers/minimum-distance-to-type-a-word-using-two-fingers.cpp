class Solution {

int solve(int i ,int p1,int p2,int n,vector<vector<vector<int>>>&dp,unordered_map<char, unordered_map<char,int>>&um1,string &word){
    if(i>=n) return 0;
    if(dp[i][p1+1][p2+1]!=-1) return dp[i][p1+1][p2+1];
    int left,right;
    if(p1==-1){
        left = 0 + solve(i+1,(word[i]-'A'),p2,n,dp,um1,word);
        
    }
    else{
        left = (um1['A'+p1][word[i]]) + solve(i+1,(word[i]-'A'),p2,n,dp,um1,word);
    }
    if(p2==-1){
        right = 0 + solve(i+1,p1,(word[i]-'A'),n,dp,um1,word);
    }
    else{
        right = (um1['A'+p2][word[i]]) + solve(i+1,p1,(word[i]-'A'),n,dp,um1,word);
    }
    return dp[i][p1+1][p2+1]=min(left,right);
}



public:
    int minimumDistance(string word) {
        unordered_map<char , vector<int>>um;
        int k=0;
        int n =word.size();
        for(int i=0;i<26;i++){
            um['A'+i] = {i/6, i%6};
        }
        unordered_map<char, unordered_map<char,int>>um1;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                um1['A'+i]['A'+j] = abs(um['A'+i][0]-um['A'+j][0]) + abs(um['A'+i][1]-um['A'+j][1]);
            }
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(27,vector<int>(27,-1)));
        
        return solve(0,-1,-1,n,dp,um1,word);
        
    }
};