class Solution {
public:
    int recursion(vector<vector<int>> &grid, int i, int j, int prev) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }

        if(prev != -1 && grid[i][j] <= prev) return 0;

        int a = recursion(grid, i - 1, j + 1, grid[i][j]);
        int b = recursion(grid, i, j + 1, grid[i][j]);
        int c = recursion(grid, i + 1, j + 1, grid[i][j]);
        return max({a, b, c}) + 1;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        for(int row = 0; row < m; row++) {
            ans = max(recursion(grid, row, 0, -1), ans);
        }

        return ans-1;
    }
};