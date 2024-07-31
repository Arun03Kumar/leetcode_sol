class Solution {
public:
    int recursion(vector<vector<int>> &triangle, int idx, int row) {
        if(row >= triangle.size()) return 0;

        int row_size;
        if(row + 1 < triangle.size())
            row_size = triangle[row + 1].size();

        int take_i_plus_1 = INT_MAX;
        if(idx + 1 < row_size) {
            take_i_plus_1 = recursion(triangle, idx + 1, row + 1);
        }

        int take_i = recursion(triangle, idx, row + 1);

        return triangle[row][idx] + min(take_i_plus_1, take_i);
    }

    int memoization(vector<vector<int>>& triangle, vector<vector<int>>& dp, int idx, int row) {
        if(row >= triangle.size()) return 0;

        if(dp[row][idx] != -1) return dp[row][idx];

        int row_size;
        if(row + 1 < triangle[row].size()) {
            row_size = triangle[row + 1].size();
        }

        int take_i_plus_1 = INT_MAX;
        if(idx + 1 < row_size) {
            take_i_plus_1 = memoization(triangle, dp, idx + 1, row + 1);
        }

        int take_i = memoization(triangle, dp, idx, row + 1);

        return dp[row][idx] = triangle[row][idx] + min(take_i_plus_1, take_i);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        // Approach 1: recursion
        // return recursion(triangle, 0, 0);


        // Approach 2: memoization
        // vector<vector<int>> dp(201, vector<int>(201, -1));
        // return memoization(triangle, dp, 0, 0);


        // Approach 3: bottom up
        int rows = triangle.size();
        vector<int> dp(rows + 1, -1);
        dp[0] = triangle[0][0];

        int idx = 0;
        for(int i = 1; i < rows; i++) {
            int min_el = triangle[i][idx];
            if(idx + 1 < triangle[i].size()) {
                min_el = min(min_el, triangle[i][idx + 1]);
                if(triangle[i][idx + 1] < triangle[i][idx]) {
                    idx = idx + 1;
                }
            }

            dp[i] = dp[i - 1] + min_el;
        }

        return dp[rows - 1];
    }
};