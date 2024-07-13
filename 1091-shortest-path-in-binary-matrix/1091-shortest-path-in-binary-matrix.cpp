class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Approach 1: BFS level wise

        // int rows = grid.size();
        // int cols = grid[0].size();

        // if(rows == 0 || cols == 0 || grid[0][0] != 0) return -1;

        // queue<pair<int, int>> q;
        // q.push({0, 0});
        // grid[0][0] = 1;

        // int ans = 1;

        // vector<vector<int>> directions{{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

        // auto is_safe = [&](int x, int y) {
        //     return x >= 0 && x < rows && y >= 0 && y < cols;
        // };

        // while(!q.empty()) {
        //     int all_nodes_at_level = q.size();
        //     while(all_nodes_at_level--) {
        //         auto curr = q.front();
        //         q.pop();

        //         int row = curr.first;
        //         int col = curr.second;

        //         if(row == rows - 1 && col == cols - 1) {
        //             return ans;
        //         }

        //         for(vector<int> v: directions) {
        //             int d_row = v[0];
        //             int d_col = v[1];

        //             int new_row = row + d_row;
        //             int new_col = col + d_col;

        //             if(is_safe(new_row, new_col) && grid[new_row][new_col] == 0) {
        //                 q.push({new_row, new_col});
        //                 grid[new_row][new_col] = 1;
        //             }
        //         }
        //     }
        //     ans++;
        // }
        // return -1;

        // Approach 2: Dijkstra's using min-heap

        int rows = grid.size(), cols = grid[0].size();

        if(rows == 0 || cols == 0 || grid[0][0] != 0) {
            return -1;
        }

        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

        vector<vector<int>> directions{{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        distance[0][0] = 0;
        grid[0][0] = 1;

        auto is_valid = [&](int x, int y) {
            return x >= 0 && x < rows && y >= 0 && y < cols;
        };

        while(!pq.empty()) {
            auto curr_node = pq.top();
            int d = curr_node.first;
            int row = curr_node.second.first;
            int col = curr_node.second.second;
            pq.pop();

            for(auto v: directions) {
                int d_row = v[0];
                int d_col = v[1];

                int new_row = row + d_row;
                int new_col = col + d_col;

                if(is_valid(new_row, new_col) && grid[new_row][new_col] == 0 &&  d + 1 < distance[new_row][new_col]) {
                    distance[new_row][new_col] = d + 1;
                    pq.push({d + 1, {new_row, new_col}});
                    grid[new_row][new_col] = 1;
                }
            }
        }

        if(distance[rows - 1][cols - 1] == INT_MAX) {
            return -1;
        }

        return distance[rows - 1][cols - 1] + 1;

    }
};