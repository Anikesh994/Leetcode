class Solution {
public:
    bool f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if (i == n - 1 && j == m - 1) return true;
        
        vis[i][j] = 1;
        int type = grid[i][j];
        int first = 0, second = 0;

        if (type == 1) {
            if (j > 0 && !vis[i][j-1] && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6))
                first = f(i, j - 1, n, m, grid, vis);

            if (j + 1 < m && !vis[i][j+1] && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5))
                second = f(i, j + 1, n, m, grid, vis);

            return first || second;
        }

        else if (type == 2) {
            if (i > 0 && !vis[i-1][j] && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4))
                first = f(i - 1, j, n, m, grid, vis);

            if (i + 1 < n && !vis[i+1][j] && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6))
                second = f(i + 1, j, n, m, grid, vis);

            return first || second;
        }

        else if (type == 3) {
            if (j > 0 && !vis[i][j-1] && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6))
                first = f(i, j - 1, n, m, grid, vis);

            if (i + 1 < n && !vis[i+1][j] && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6))
                second = f(i + 1, j, n, m, grid, vis);

            return first || second;
        }

        else if (type == 4) {
            if (j + 1 < m && !vis[i][j+1] && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5))
                first = f(i, j + 1, n, m, grid, vis);

            if (i + 1 < n && !vis[i+1][j] && (grid[i+1][j] == 2 || grid[i+1][j] == 5 || grid[i+1][j] == 6))
                second = f(i + 1, j, n, m, grid, vis);

            return first || second;
        }

        else if (type == 5) {
            if (j > 0 && !vis[i][j-1] && (grid[i][j-1] == 1 || grid[i][j-1] == 4 || grid[i][j-1] == 6))
                first = f(i, j - 1, n, m, grid, vis);

            if (i > 0 && !vis[i-1][j] && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4))
                second = f(i - 1, j, n, m, grid, vis);

            return first || second;
        }

        else if (type == 6) {
            if (j + 1 < m && !vis[i][j+1] && (grid[i][j+1] == 1 || grid[i][j+1] == 3 || grid[i][j+1] == 5))
                first = f(i, j + 1, n, m, grid, vis);

            if (i > 0 && !vis[i-1][j] && (grid[i-1][j] == 2 || grid[i-1][j] == 3 || grid[i-1][j] == 4))
                second = f(i - 1, j, n, m, grid, vis);

            return first || second;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return f(0, 0, n, m, grid, vis);
    }
};