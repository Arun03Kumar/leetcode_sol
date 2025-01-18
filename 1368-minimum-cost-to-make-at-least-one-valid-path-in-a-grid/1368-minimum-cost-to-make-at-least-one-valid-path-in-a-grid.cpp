class Solution {
public:
    int recursion(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 10000;
        }

        if(visited[i][j] == 1) return 10000;

        if(i == grid.size() - 1 && j == grid[0].size() - 1) return 0;

        visited[i][j] = 1;

        int a = 10000, b = 10000, c = 10000, d = 10000;
        if(grid[i][j] == 1) {
            a = recursion(grid, i, j + 1, visited);
            b = 1 + recursion(grid, i, j - 1, visited);
            c = 1 + recursion(grid, i + 1, j, visited);
            d = 1 + recursion(grid, i - 1, j, visited);
        }
        else if(grid[i][j] == 2) {
            a = 1 + recursion(grid, i, j + 1, visited);
            b = recursion(grid, i, j - 1, visited);
            c = 1 + recursion(grid, i + 1, j, visited);
            d = 1 + recursion(grid, i - 1, j, visited);
        }
        else if(grid[i][j] == 3) {
            a = 1 + recursion(grid, i, j + 1, visited);
            b = 1 + recursion(grid, i, j - 1, visited);
            c = recursion(grid, i + 1, j, visited);
            d = 1 + recursion(grid, i - 1, j, visited);
        }
        else {
            a = 1 + recursion(grid, i, j + 1, visited);
            b = 1 + recursion(grid, i, j - 1, visited);
            c = 1 + recursion(grid, i + 1, j, visited);
            d = recursion(grid, i - 1, j, visited);
        }
        visited[i][j] = 0;
        return min({a, b, c, d});
    }

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        // Backtracking Approach:

        // int cost = 0;
        // int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> visited(m, vector<int>(n, 0));
        // return recursion(grid, 0, 0, visited);


        // Approach 2: Dijkstras

        int m = grid.size();
        int n = grid[0].size();

        // <cost, i, j> is stored in the pq
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        ans[0][0] = 0;

        while(!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int x = top[1];
            int y = top[2];
            int cost = top[0];

            if(ans[x][y] < cost) continue;

            for(int i = 0; i <= 3; i++) {
                int new_x = x + directions[i][0];
                int new_y = y + directions[i][1];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    int grid_direction = grid[x][y];
                    int dir_cost = ((grid_direction - 1 != i) ? 1 : 0);

                    int new_cost = cost + dir_cost;

                    if(new_cost < ans[new_x][new_y]) {
                        ans[new_x][new_y] = new_cost;
                        pq.push({new_cost, new_x, new_y});
                    }
                }
            }
        }

        return ans[m - 1][n - 1];
    }
};