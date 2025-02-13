class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2));

        for(int i = 0; i < n - 3 + 1; i++) {
            for(int j = 0; j < n - 3 + 1; j++) {

                int temp = grid[i][j];
                for(int k = i; k < i + 3; k++) {
                    for(int l = j; l < j + 3; l++) {
                        temp = max(temp, grid[k][l]);
                    }
                }

                ans[i][j] = temp;
            }
        }

        return ans;
    }
};