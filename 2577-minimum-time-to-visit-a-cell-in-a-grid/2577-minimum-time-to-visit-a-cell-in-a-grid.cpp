class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        q.push({0, 0});
        visited[0][0] = 1;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto front = q.front();
                int x = front.first;
                int y = front.second;
                q.pop();

                for(vector<int> &dir: directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y]) {
                        if(level >= grid[new_x][new_y]) {
                            q.push({new_x, new_y});
                            visited[new_x][new_y] = 1;

                            if(new_x == m - 1 && new_y == n - 1) return level;

                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};