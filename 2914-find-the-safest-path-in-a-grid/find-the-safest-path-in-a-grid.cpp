class Solution {
vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
 
 bool check(int mid , vector<vector<int>>&dist){
    if(dist[0][0] < mid) return false;
    vector<vector<bool>>vis(dist.size() , vector<bool>(dist[0].size(),false));
    vis[0][0]=true;
    queue<pair<int,int>>qt;
    qt.push({0,0});
    while(!qt.empty()){
        auto it= qt.front();
        qt.pop();
        if(it.first==dist.size()-1 && it.second==dist[0].size()-1) return true;
        for(int i=0;i<4;i++){
            int nr = it.first + dir[i][0];
            int nc = it.second + dir[i][1];
            if(nr>=0 && nr <dist.size() && nc>=0 && nc<dist[0].size() && !vis[nr][nc]){
                vis[nr][nc]=true;
                if(dist[nr][nc]>=mid){
                    qt.push({nr,nc});
                }
                
            }
        }
    }
    return false;
 }


public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        vector<vector<int>>temp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>qt;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    temp[i][j]=0;
                    qt.push({i,j});
                }
            }
        }

        while(!qt.empty()){
            auto it = qt.front();
            qt.pop();
            for(int i=0;i<4;i++){
                int nr= it.first + dir[i][0];
                int nc= it.second + dir[i][1];
                if(nr>=0 && nr <n && nc>=0 && nc<m && temp[nr][nc]==INT_MAX){
                    temp[nr][nc] =temp[it.first][it.second]+1;
                    qt.push({nr,nc});
                }
            }
        }
        int low=0;
        int high =n+m;
        int ans=0;
        while(low <=high){
            int mid = (low +high)/2;
            if(check(mid,temp)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};