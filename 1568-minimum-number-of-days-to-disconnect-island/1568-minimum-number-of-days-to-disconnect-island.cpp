class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m;
    int n;
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return;
        
        visited[i][j] = 1; //mark visited

        for(auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            DFS(grid, new_i, new_j, visited);
        }
    }

    int numberOfIslandsDFS(vector<vector<int>>& grid) {

        vector<vector<bool>> visited(m, vector<bool>(n));
        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) { //DFS
                    DFS(grid, i, j, visited);
                    islands += 1;
                }
            }
        }

        return islands;
    } 

    int minDays(vector<vector<int>>& grid) {
        // so based on observation it is possible to make graph disconnected in either 0, 1 or 2 days, if there is 1 or 0 land component then number of days is 0.
        // then we again check on traversing each grid element and make it to 0 a water then again check number of land if it is 2 then return 1.
        // else return 2 because any grid can be disconnected in 2 days just make diagonal elements 0. as given in example.
        
        m = grid.size();
        n = grid[0].size();
        int islands = numberOfIslandsDFS(grid);

        //Grid already disconnected
        if (islands > 1 or islands == 0) {
            return 0;
        } else {
			// check for 1 ans
            for (int i = 0 ; i < m; i ++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0; //visited
						
                        islands = numberOfIslandsDFS(grid);
						
                        grid[i][j] = 1; //unvisited
                        if (islands > 1 or islands == 0)
                            return 1;
                    }

                }
            }
        }

        return 2; //It's always possible to break an island with 2 moves
    }
};