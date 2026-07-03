class Solution {

bool check(int mid ,vector<vector<pair<int,int>>>&adj ,long long k){
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,0});
    int n = adj.size();
    vector<long long> vis(n, LLONG_MAX);
    vis[0] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second == adj.size()-1) return true;
        if(it.first > vis[it.second]) continue;
        
        for(auto it1 : adj[it.second]){
            int x= it.first + it1.second;
            if(x >k || it1.second < mid || vis[it1.first] < x) continue;
            vis[it1.first] = x;
            pq.push({x,it1.first });
        }
    }
    return false;
}


public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n =online.size();
        vector<vector<pair<int,int>>>adj(n);
        int low =INT_MAX;
        int high =INT_MIN;
        for(int i=0;i<edges.size();i++){
            if(!online[edges[i][0]] || !online[edges[i][1]]) continue;
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            low = min(low,edges[i][2]);
            high = max(high,edges[i][2]);
        }

        int ans=-1;
        while(low<=high){
            int mid =(low+high)/2;
            if(check(mid , adj,k)){
                ans=mid;
                low =mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;

    }
};