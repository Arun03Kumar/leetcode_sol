class Solution {
public: 
    int dfs(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &vis) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || vis[r][c] == 1) {
            return 0;
        }

        vis[r][c] = 1;

        int a = dfs(grid, r + 1, c, vis);
        int b = dfs(grid, r - 1, c, vis);
        int x = dfs(grid, r, c + 1, vis);
        int d = dfs(grid, r, c - 1, vis);

        return a + b + x + d + grid[r][c];
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0 && visited[i][j] == 0) {
                   ans = max(ans, dfs(grid, i, j, visited));
                }
            }
        }

        return ans;
    }
};