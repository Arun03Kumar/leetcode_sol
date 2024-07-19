class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col] == 1) {
            return;
        }

        visited[row][col] = 1;
        for(auto dir: directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            dfs(grid, visited, new_row, new_col);
        }

    }

    int bfs(vector<vector<int>>& grid, vector<vector<int>> &visited) {
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(visited[i][j]) {
                    q.push({i, j});
                }
            }
        }

        int level = 0;

        auto is_valid = [&](int p1, int p2) {
            return p1 >= 0 && p1 < grid.size() && p2 >= 0 && p2 < grid[0].size();
        };

        while(!q.empty()) {

            int N = q.size();
            while(N--) {

                auto front = q.front();
                q.pop();

                int r = front.first;
                int c = front.second;

                if(visited[r][c] == 0 && grid[r][c] == 1) {
                    return level;
                }

                for(auto dir: directions) {

                    int new_r = r + dir[0];
                    int new_c = c + dir[1];

                    if(is_valid(new_r, new_c) && !visited[new_r][new_c]) {

                        if(grid[new_r][new_c] == 1) return level;

                        visited[new_r][new_c] = 1;
                        q.push({new_r, new_c});

                    }

                }

            }
            level++;

        }

        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        // first do dfs on a cell with 1 value, this will mark all the connected land.
        // then do level wise bfs.
        // so which cells are visited push them into queue in the start, because they all will be at level 1, since we want shortest route. 

        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0)); 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                    return bfs(grid, visited);
                }
            }
        }

        return -1;
    }
};