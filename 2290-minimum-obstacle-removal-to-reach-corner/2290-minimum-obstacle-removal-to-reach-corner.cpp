class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        pq.push({0, 0, 0});
        visited[0][0] = 1;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int x = top[1];
            int y = top[2];
            int wt = top[0];

            for(vector<int> &dir: directions) {
                int dx = dir[0];
                int dy = dir[1];

                if(x + dx == m - 1 && y + dy == n - 1) return wt;

                if(x + dx >= 0 && x + dx < grid.size() && y + dy >= 0 && y + dy < grid[0].size()) {
                    if(!visited[x + dx][y + dy]) {
                        if(grid[x + dx][y + dy] == 1) {
                            pq.push({wt + 1, x + dx, y + dy});
                        }
                        else {
                            pq.push({wt, x + dx, y + dy});
                        }
                        visited[x + dx][y + dy] = 1;
                    }
                }
            }

        }
        return -1;

    }
};