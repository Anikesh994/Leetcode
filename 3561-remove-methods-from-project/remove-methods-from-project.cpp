class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        bool t=false;
        for(auto it : invocations){
            adj[it[0]].push_back(it[1]);
        }
        queue<int>qt;
        qt.push(k);
        unordered_map<int,int>mp;
        while(!qt.empty()){
            auto it = qt.front();
            qt.pop();
            if(mp.count(it)) continue;
            mp[it]++;
            for(auto it1 : adj[it]){
                qt.push(it1);
            }
            
        }
        vector<int>ans;
        for(auto it : invocations){
            if(!mp.count(it[0]) && mp.count(it[1])){
                
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }

        for(int i=0;i<n;i++){
            if(mp.count(i)) continue;
            ans.push_back(i);
        }
        return ans;


    }
};