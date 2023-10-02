class Solution {
public:
    void bfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> grid) {
        // cout << visited[r][c] << " ";
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        visited[r][c] = 1;
        while(!q.empty()) {
            auto front = q.front();
        q.pop();
        int x = front.first, y = front.second;
        cout << x<<y << " ";
        if(x+1 < grid.size() && grid[x+1][y] == '1' && visited[x+1][y] == 0) {
                q.push(make_pair(x+1, y));
                visited[x+1][y] = 1;
            }
            if(x-1 >= 0 && visited[x-1][y] == 0 && grid[x-1][y] == '1') {
                q.push(make_pair(x-1, y));
                visited[x-1][y] = 1;
            }
            if(y- 1 >= 0 && visited[x][y-1] == 0 && grid[x][y-1] == '1') {
                q.push(make_pair(x, y-1));
                visited[x][y-1] = 1;
            }
            if(y+1 < grid[0].size() && visited[x][y+1] == 0 && grid[x][y+1] == '1') {
                q.push(make_pair(x, y+1));
                visited[x][y+1] =1 ;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                // cout << visited[i][j] << " ";
                if(visited[i][j] == 0 && grid[i][j] == '1') {
                   bfs(i, j, visited, grid);
                   
                //    cout << i<<j << " ";
                    ans++;
                }
                 
            }
        }
        return ans;
    }
};