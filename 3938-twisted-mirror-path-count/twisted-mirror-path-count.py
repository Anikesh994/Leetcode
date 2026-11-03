class Solution:
    def uniquePaths(self, grid: list[list[int]]) -> int:
        MOD = 10**9 + 7
        n = len(grid[0])
        
        # d[j] represents paths coming from above for each column
        d = [1] + [0] * (n - 1)
        
        for row in grid:
            res = 0  # Paths coming from the left
            for j, x in enumerate(row):
                if x == 1:
                    # Mirror: swap the left and above flow directions
                    res, d[j] = d[j], res
                else:
                    # Empty cell: combine and split flows
                    res = d[j] = (res + d[j]) % MOD
                    
        return res