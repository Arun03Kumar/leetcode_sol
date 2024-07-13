class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Approach 1: BFS

        int rows = grid.size();
        int cols = grid[0].size();

        if(rows == 0 || cols == 0 || grid[0][0] != 0) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int ans = 1;

        vector<vector<int>> directions{{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

        auto is_safe = [&](int x, int y) {
            return x >= 0 && x < rows && y >= 0 && y < cols;
        };

        while(!q.empty()) {
            int all_nodes_at_level = q.size();
            while(all_nodes_at_level--) {
                auto curr = q.front();
                q.pop();

                int row = curr.first;
                int col = curr.second;

                if(row == rows - 1 && col == cols - 1) {
                    return ans;
                }

                for(vector<int> v: directions) {
                    int d_row = v[0];
                    int d_col = v[1];

                    int new_row = row + d_row;
                    int new_col = col + d_col;

                    if(is_safe(new_row, new_col) && grid[new_row][new_col] == 0) {
                        q.push({new_row, new_col});
                        grid[new_row][new_col] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;

    }
};