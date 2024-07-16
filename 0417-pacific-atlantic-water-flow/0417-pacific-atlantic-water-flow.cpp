class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int r, int c) {
        if(r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || visited[r][c] == 1) {
            return;
        }

        visited[r][c] = 1;

        for(auto dir: directions) {
            int new_r = r + dir[0];
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < heights.size() && new_c >= 0 && new_c < heights[0].size() && heights[new_r][new_c] >= heights[r][c]) {

                dfs(heights, visited, new_r, new_c);

            }

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // create two visited array and make dfs for both oceans seperately
        // for pacific ocean start from top row and first column and check if neighbouring cells are have greater height than them this will tell that water can flow from neighbouring cell to the pacific ocean;

        // simillarly do for atlantic ocean
        //in both visited array where coordinates will overlap that will be the answer

        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> pacific(row, vector<int>(col, 0));
        vector<vector<int>> atlantic(row, vector<int>(col, 0));

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {

                if(r == 0 || c == 0) {
                    dfs(heights, pacific, r, c);
                }

                if(r == row - 1 || c == col - 1) {
                    dfs(heights, atlantic, r, c);
                }

            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};