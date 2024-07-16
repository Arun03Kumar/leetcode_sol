class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // int max_time = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int max_time = 0;

        auto is_valid = [&](int p1, int p2) {
            return p1 >= 0 && p1 < grid.size() && p2 >= 0 && p2 < grid[0].size();
        };

        while(!q.empty()) {

            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();

            for(auto dir: directions) {

                int dx = dir[0];
                int dy = dir[1];

                int new_x = x + dx;
                int new_y = y + dy;

                if(is_valid(new_x, new_y) && grid[new_x][new_y] != 0 && visited[new_x][new_y] == 0) {

                    visited[new_x][new_y] = 2;
                    q.push({{new_x, new_y}, time + 1});
                    max_time = max(max_time, time + 1);

                }

            }

        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return max_time;
    }
};