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

        // return recursion(triangle, 0, 0);

        vector<vector<int>> dp(201, vector<int>(201, -1));
        return memoization(triangle, dp, 0, 0);


    }
};