class Solution {

vector<vector<int>>dir = {{-1,0},{1,0},{0,-1},{0,1}};


bool solve(vector<vector<int>>& grid, int health){
    if(health<=0) return false;
    priority_queue<vector<int> , vector<vector<int>> >pq;
    int x= health;
    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
    int startHealth = health - grid[0][0];
    if(startHealth <= 0) return false;
    pq.push({startHealth, 0, 0});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(vis[it[1]][it[2]] != -1) continue;
        vis[it[1]][it[2]] = 0;

        if(it[1]==grid.size()-1 && it[2]==grid[0].size()-1) return true;
        for(auto it1 : dir){
            int nr = it[1] + it1[0];
            int nc = it[2] + it1[1];

            if(nr>=0 && nc >=0 && nr < grid.size() && nc< grid[0].size() && vis[nr][nc]==-1){
                int newHealth = it[0] - grid[nr][nc];
                if(newHealth > 0){
                    pq.push({newHealth, nr, nc});
                }
                
            }
        }

    }
    return false;
}



public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return solve(grid,health);
    }
};