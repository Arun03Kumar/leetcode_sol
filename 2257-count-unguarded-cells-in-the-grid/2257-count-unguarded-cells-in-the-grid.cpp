class Solution {
public:
    void mark_grid(vector<vector<int>> &ans, int row, int col) {
        // mark all cell in left of ans[row][col]
        for(int i = row - 1; i >= 0; i--) {
            if(ans[i][col] == 2 || ans[i][col] == 3) break;
            ans[i][col] = 1;
        }

        // mark all cell in right of ans[row][col]
        for(int i = row + 1; i < ans.size(); i++) {
            if(ans[i][col] == 2 || ans[i][col] == 3) break;
            ans[i][col] = 1;
        }

        // mark all cell in top of ans[row][col]
        for(int i = col - 1; i >= 0; i--) {
            if(ans[row][i] == 2 || ans[row][i] == 3) break;
            ans[row][i] = 1;
        }

        // mark all cell in down of ans[row][col]
        for(int i = col + 1; i < ans[0].size(); i++) {
            if(ans[row][i] == 2 || ans[row][i] == 3) break;
            ans[row][i] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // mark guards as 2 and walls as 3
        // mark those positions as 1 which can be guarded

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(vector<int> &v: guards) {
            int i = v[0];
            int j = v[1];
            ans[i][j] = 2;
        }

        for(vector<int> &v: walls) {
            int i = v[0];
            int j = v[1];
            ans[i][j] = 3;
        }

        for(vector<int> &v: guards) {
            int r = v[0];
            int c = v[1];
            mark_grid(ans, r, c);
        }

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(ans[i][j] == 0) count++;
            }
        }

        return count;
    }
};