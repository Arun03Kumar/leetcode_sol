class Solution {
public:
    int recursion(vector<vector<int>> &mat, int i, int j) {
        if(i >= mat.size() || j >= mat[0].size()) return 0;

        if(mat[i][j] == 0) return 0;

        int right = recursion(mat, i, j + 1);
        int diag = recursion(mat, i + 1, j + 1);
        int bottom = recursion(mat, i + 1, j);

        return 1 + min({right, diag, bottom});
    }

    int memoization(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp) {
        if(i >= mat.size() || j >= mat[0].size()) return 0;

        if(mat[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = memoization(mat, i, j + 1, dp);
        int diag = memoization(mat, i + 1, j + 1, dp);
        int bottom = memoization(mat, i + 1, j, dp);

        return dp[i][j] = 1 + min({right, diag, bottom});
    }

    int countSquares(vector<vector<int>>& matrix) {
        // Approach 1: recursion
        // for each index we are searchin how many ones are ther in 3 directions, right, bottom and in diagonal
        // for each index we get these three values, so the number of square matrix will be equal to have size minimum to these three which will contains all 1s
        // but the current index will also be considered as in answer becuse 1 is there
        // int m = matrix.size();
        // int n = matrix[0].size();

        // int ans = 0;
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {

        //         if(matrix[i][j] == 1) {
        //             ans += recursion(matrix, i, j);
        //         }

        //     }
        // }

        // return ans;


        // Approach 2: memoization

        // int m = matrix.size();
        // int n = matrix[0].size();

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // int ans = 0;
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {

        //         if(matrix[i][j] == 1) {
        //             ans += memoization(matrix, i, j, dp);
        //         }

        //     }
        // }

        // return ans;


        // Approach 3: bottom-up

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;

        for(int i = 0; i < m; i++) {
            if(matrix[i][n - 1] == 1) {
                dp[i][n - 1] = 1;
                ans++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(matrix[m - 1][i] == 1) {
                dp[m - 1][i] = 1;
                ans++;
            }
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {

                if(matrix[i][j] == 1) {
                    int right = dp[i][j + 1];
                    int diag = dp[i + 1][j + 1];
                    int bottom = dp[i + 1][j];

                    dp[i][j] = 1 + min({right, diag, bottom});
                    ans += dp[i][j];
                }

            }
        }

        ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
                ans += dp[i][j];
            }
            cout << endl;
        }

        return ans;
    }
};