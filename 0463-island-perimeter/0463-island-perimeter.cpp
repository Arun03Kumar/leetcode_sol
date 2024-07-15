class Solution {
public:
    vector<vector<int> > directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& grid, int i, int j, int &ans) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            ans++;
            return;
        }

        if(grid[i][j] == -1) return;

        grid[i][j] = -1;

        for(auto x: directions) {
            int dx = x[0];
            int dy = x[1];

            DFS(grid, i + dx, j + dy, ans);
        }

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    DFS(grid, i, j, ans);
                    return ans;
                }
            }
        }
        return ans;
    }
};