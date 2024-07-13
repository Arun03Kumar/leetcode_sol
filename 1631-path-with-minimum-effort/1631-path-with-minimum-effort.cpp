class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<int>> h_distance(rows, vector<int>(cols, INT_MAX));
        // vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        h_distance[0][0] = 0;
        pq.push({0, {0, 0}});
        // visited[0][0] = 1;

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

                if(is_valid(new_row, new_col)) {
                    int abs_diff = abs(heights[row][col] - heights[new_row][new_col]);
                    int max_diff = max(d, abs_diff);

                    if(max_diff < h_distance[new_row][new_col]) {
                        h_distance[new_row][new_col] = max_diff;
                        pq.push({max_diff, {new_row, new_col}});
                    }
                }
            }
        }
        return h_distance[rows - 1] [ cols - 1];
    }
};