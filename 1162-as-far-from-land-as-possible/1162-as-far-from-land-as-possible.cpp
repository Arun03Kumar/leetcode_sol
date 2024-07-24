class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxDistance(vector<vector<int>>& grid) {
        // thought in the reverse manner, from all the land find the distance of waters
        // do the level order traversel from lands and return the level.
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        bool flag = false;
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    
                    count++;
                    // flag = true;
                }
            }
        }

        if(count == 0 || count == m * n) return -1;

        int level = 0;

        auto is_valid = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        while(!q.empty()) {
            int q_size = q.size();
            while(q_size--) {

                auto front = q.front();
                q.pop();

                int r = front.first;
                int c = front.second;

                for(auto dir: directions) {

                    int new_r = r + dir[0];
                    int new_c = c + dir[1];

                    if(is_valid(new_r, new_c) && grid[new_r][new_c] == 0 && visited[new_r][new_c] == 0) {

                        visited[new_r][new_c] = 1;
                        q.push({new_r, new_c});

                    }

                }

            }
            level++;
        }

        return level - 1;
    }
};