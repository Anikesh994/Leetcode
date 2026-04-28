class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        int x1 = temp[temp.size()/2];
        int ans=0;
        int y = temp[0]%x;
        for(int i=0;i<temp.size();i++){
            if(temp[i]%x != y) return -1;
            ans+=(abs(temp[i]-x1)/x);
        }
        return ans;
    }
};