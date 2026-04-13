class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n =matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            int x=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1) x++;
            }
            ans.push_back(x);
        }
        return ans;
    }
};