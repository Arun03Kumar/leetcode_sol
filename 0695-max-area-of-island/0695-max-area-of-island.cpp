class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int BFS(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        int area = 0;

        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push({i, j});
        area++;
        
        auto is_valid = [&](int p1, int p2) {
            return p1 >= 0 && p1 < grid.size() && p2 >= 0 && p2 < grid[0].size();
        };

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto dir: directions) {
                int dx = dir[0];
                int dy = dir[1];
                
                int new_x = x + dx;
                int new_y = y + dy;

                if(is_valid(new_x, new_y) && grid[new_x][new_y] == 1 && visited[new_x][new_y] == 0) {
                    area++;
                    visited[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    int area = BFS(grid, visited, i, j);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};