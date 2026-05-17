class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int layer = 0;

        for(int i = 0; i < min(n, m) / 2; i++) {

            vector<int> nums;

            int top = layer;
            int left = layer;
            int bottom = n - layer - 1;
            int right = m - layer - 1;

            for(int i = left; i < right; i++)
                nums.push_back(grid[top][i]);

            for(int i = top; i < bottom; i++)
                nums.push_back(grid[i][right]);

            for(int i = right; i > left; i--)
                nums.push_back(grid[bottom][i]);
            for(int i = bottom; i > top; i--)
                nums.push_back(grid[i][left]);

            int rot = k % nums.size();
            for(int i = left; i < right; i++) {
                grid[top][i] = nums[rot];
                rot = (rot + 1) % nums.size();
            }
            for(int i = top; i < bottom; i++) {
                grid[i][right] = nums[rot];
                rot = (rot + 1) % nums.size();
            }
            for(int i = right; i > left; i--) {
                grid[bottom][i] = nums[rot];
                rot = (rot + 1) % nums.size();
            }
            for(int i = bottom; i > top; i--) {
                grid[i][left] = nums[rot];
                rot = (rot + 1) % nums.size();
            }

            layer++;
        }

        return grid;
    }
};