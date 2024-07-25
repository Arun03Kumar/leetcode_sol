class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] == 0) {
            return 0;
        }

        visited[i][j] = 1;

        int a = dfs(grid, visited, i + 1, j);
        int b = dfs(grid, visited, i - 1, j);
        int c = dfs(grid, visited, i, j + 1);
        int d = dfs(grid, visited, i, j - 1);

        visited[i][j] = 0;

        return max(a, max(b, max(c, d))) + grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = INT_MIN;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    vector<vector<int>> visited(m, vector<int>(n, 0));

                    int temp = dfs(grid, visited, i, j);
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }
};