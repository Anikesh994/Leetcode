class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int,vector<int>>temp;
        for(int i=0;i<n;i++){
            temp[arr[i]].push_back(i);
        }
        queue<pair<pair<int,int>,int>>qt;
        vector<int>vis(n,-1);
        qt.push({{arr[0],0},0});
        int ans=-1;
        vis[0]=1;
        while(!qt.empty()){
            auto it =qt.front();
            qt.pop();
            if(it.first.second==n-1){
                ans =it.second;
                break;
            }
            if(it.first.second+1 < n && vis[it.first.second+1]==-1){
                vis[it.first.second+1]=1;
                qt.push({{arr[it.first.second+1],it.first.second+1},it.second+1});
            }
            if(it.first.second > 0 && vis[it.first.second-1]==-1){
                qt.push({{arr[it.first.second-1],it.first.second-1},it.second+1});
                vis[it.first.second-1]=1;
            }
            for(auto it1 : temp[it.first.first]){
                if(vis[it1]==-1){
                    vis[it1]=1;
                    qt.push({{arr[it1],it1},it.second+1});
                }
            }
            temp[it.first.first].clear();
            

        }
        return ans;
    }
};