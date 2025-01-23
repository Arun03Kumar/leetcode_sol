class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &vis) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j]) return 0;

        vis[i][j] = 1;

        int a = dfs(grid, i + 1, j, vis);
        int b = dfs(grid, i - 1, j, vis);
        int c = dfs(grid, i, j + 1, vis);
        int d = dfs(grid, i, j - 1, vis);

        return max({a, b, c, d}) + 1;
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    int cnt = dfs(grid, i, j, visited);
                    cout << cnt << " ";
                    ans += (cnt == 1 ? 0 : cnt);
                }
            }
        }    

        return ans;
    }
};