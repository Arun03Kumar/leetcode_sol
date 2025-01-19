class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        // boundary cells can not store any water, so we are starting from smallest hight cell
        // and for all 4 directions we check if can store any water, 
        // if we are at any lower height cell and neighbouring cell is greater then it stores 0 in the answer because their height difference will be 0
        // if current cell is greater than the neighbouring cell then we add the updated height of neighbouring cell
        
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int row = 0; row < m; row++) {
            for(int col: {0, n - 1}) {
                pq.push({heightMap[row][col], row, col});
                visited[row][col] = 1;
            }
        }

        for(int col = 0; col < n; col++) {
            for(int row: {0, m - 1}) {
                pq.push({heightMap[row][col], row, col});
                visited[row][col] = 1;
            }
        }

        int ans = 0;
        while(!pq.empty()) {
            int height = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            for(vector<int> &dir: directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y]) {
                    ans += max(height - heightMap[new_x][new_y], 0);
                    pq.push({max(height, heightMap[new_x][new_y]), new_x, new_y});  
                    visited[new_x][new_y] = 1; 
                }
            }
        }

        return ans;
    }
};