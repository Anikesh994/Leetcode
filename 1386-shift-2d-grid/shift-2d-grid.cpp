class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k = k%(m*n);
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }
        int x=n*m-k;
        int q=0;
        int j=0;
        for(int i=0;i<n*m;i++){
            grid[j][q]=temp[(x+i)%(n*m)];
            q++;
            if(q==m){
                j++;
                q=0;
            }
           
        }
        return grid;
        
    }
};