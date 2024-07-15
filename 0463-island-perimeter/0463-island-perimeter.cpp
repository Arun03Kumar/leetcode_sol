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

    void BFS(vector<vector<int>>& grid, int i, int j, int &ans) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;

        auto is_invalid = [&](int p1, int p2) {
            return p1 < 0 || p1 >= grid.size() || p2 < 0 || p2 >= grid[0].size() || grid[p1][p2] == 0;
        };

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto dir: directions) {
                int new_x = x + dir[0]; 
                int new_y = y + dir[1];

                if(is_invalid(new_x, new_y)) {
                    ans++;
                }
                else if(grid[new_x][new_y] == -1) {
                    continue;
                }
                else {
                    grid[new_x][new_y] = -1;
                    q.push({new_x, new_y});
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    // DFS(grid, i, j, ans);
                    BFS(grid, i, j, ans);
                    return ans;
                }
            }
        }
        return ans;
    }
};