class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int n1 = roads.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<n1;i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int ans = INT_MAX;
        queue<pair<int,int>>qt;
        qt.push({1,INT_MAX});
        vector<bool>vis(n , false);
        while(!qt.empty()){
            auto it = qt.front();
            qt.pop();
            vis[it.first]=true;
            ans=min(ans,it.second);
            for(auto it1 : adj[it.first]){
                if(!vis[it1.first]){
                    qt.push(it1);
                }
            }
        }
        return ans;
    }
};