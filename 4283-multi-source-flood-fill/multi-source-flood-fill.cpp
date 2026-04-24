class Solution {
public:
    struct cmp{
        bool operator()(const vector<int> &a ,const vector<int>&b){
            if (a[0] == b[0]) return a[3] < b[3]; // max color if same time
            return a[0] > b[0]; 
        }
    };
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>ans(n,vector<int>(m,0));
        priority_queue<vector<int> , vector<vector<int>> , cmp>q;
        for(int i=0;i<sources.size();i++){
            q.push({0, sources[i][0], sources[i][1], sources[i][2]});
            ans[sources[i][0]][sources[i][1]] = sources[i][2];
        }
        int ar1[4] ={-1,1,0,0};
        int ar2[4] ={0,0,1,-1};
        while(q.size()!=0){
            auto x= q.top();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=ar1[i]+x[1];
                int nc=ar2[i] + x[2];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == 0){
                    ans[nr][nc]=ans[x[1]][x[2]];
                    q.push({x[0]+1 ,nr,nc,ans[nr][nc]});
                }
            }

        }
        return ans;
    }
};