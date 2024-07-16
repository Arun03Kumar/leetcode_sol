class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>> &visited, int i, int j, int &flag) {
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0 || visited[i][j] == 1) {
            return;
        }

        visited[i][j] = 1;

        if(grid1[i][j] != 1) {
            flag = 0;
        }

        for(auto dir: directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            DFS(grid1, grid2, visited, new_i, new_j, flag);

        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        // traverse over grid2 and run DFS over land when there is a land correspondingly check if in grid1 land is also present at that location if not then mark the flag variable as 0 it means this land is not a subland;

        int m = grid2.size();
        int n = grid2[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid2[i][j] == 1 && visited[i][j] == 0) {

                    int flag = 1;
                    DFS(grid1, grid2, visited, i, j, flag);
                    ans += flag;

                }

            }
        }

        return ans;
    }
};