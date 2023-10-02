class Solution {
public:
    void bfs(int r, int c, int nVal, vector<vector<int>>& image, vector<vector<int>> &visited, int num) {
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first, y = front.second;
            if(x+1 < image.size() && visited[x+1][y] == 0 && image[x+1][y] == num) {
                visited[x+1][y] = 1;
                q.push({x+1, y});
                image[x+1][y] = nVal;
            }
            if(x-1 >= 0 && visited[x-1][y] == 0 && image[x-1][y] == num) {
                visited[x-1][y] = 1;
                q.push({x-1, y});
                image[x-1][y] = nVal;
            }
            if(y+1 < image[0].size() && visited[x][y+1] == 0 && image[x][y+1] == num) {
                visited[x][y+1] = 1;
                q.push({x, y+1});
                image[x][y+1] = nVal;
            }
            if(y-1 >= 0 && visited[x][y-1] == 0 && image[x][y-1] == num) {
                visited[x][y-1] = 1;
                q.push({x, y-1});
                image[x][y-1] = nVal;
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        bfs(sr, sc, color, image, visited, image[sr][sc]);
        image[sr][sc] = color;
        return image;
    }
};