class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0  || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }

        if(grid[i][j] == 1) return true;

        grid[i][j] = 1;

        int left = dfs(grid, i - 1, j);
        int right = dfs(grid, i + 1, j);
        int top = dfs(grid, i, j - 1);
        int bottom = dfs(grid, i, j + 1);

        return left && right && top && bottom;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    bool temp = dfs(grid, i, j);
                    if(temp) ans++;
                }
            }
        }

        return ans;
    }
};