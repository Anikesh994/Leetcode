class Solution {

void solve(int c,int q ,vector<int>&t1 , vector<vector<int>>&vis , unordered_map<int,vector<int>>&temp){
    queue<int>qt;
    qt.push(q);
    t1[q]=c;
    while(!qt.empty()){
        auto it  = qt.front();
        qt.pop();
       
        temp[c].push_back(it);
        for(auto it1 : vis[it]){
            if(t1[it1]==-1){
                 t1[it1] = c;
                qt.push(it1);
            }
        }
    }
}



public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vis(n);
        for(auto it : edges){
            vis[it[0]].push_back(it[1]);
            vis[it[1]].push_back(it[0]);
        }
        unordered_map<int,vector<int>>temp;
        int c=0;
        vector<int>t1(n,-1);

        for(int i=0;i<n;i++){
            if(t1[i]==-1){
                solve(c , i , t1 ,vis , temp);
                c++;
            }
        }

        int ans=0;
        for(auto it : temp){
            int x= it.second.size();
            bool t=true;
            for(auto it1 : it.second){
                if(vis[it1].size() != x-1){
                    t=false;
                    break;
                }
            }
            if(t) ans++;
        }
        return ans;
    }
};