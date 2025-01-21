class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // int n = grid[0].size();
        // vector<vector<long long>> prefix(2, vector<long long>(n, 0));
        // prefix[0][0] = grid[0][0];
        // prefix[1][0] = grid[1][0];

        // for(int i = 1; i < n; i++) {
        //     prefix[0][i] = prefix[0][i - 1] + grid[0][i];
        // }
        // for(int i = 1; i < n; i++) {
        //     prefix[1][i] = prefix[1][i - 1] + grid[1][i];
        // }

        // long long ans = LLONG_MAX;
        // for(int i = 0; i < n; i++) {
        //     long long top = (i == n - 1) ? 0 : prefix[0][n - 1] - prefix[0][i];
        //     long long bottom = (i == 0) ? 0 : prefix[1][i - 1];

        //     ans = min(ans, max(top, bottom));
        // }

        // return ans;


        // Approach 2: without extra space
        int n = grid[0].size();
        long long top_row_sum = accumulate(begin(grid[0]), end(grid[0]), 0 * 1LL);
        long long bottom_row_sum = 0;

        long long curr_top_sum = 0;
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            curr_top_sum += grid[0][i];
            ans = min(ans, max(bottom_row_sum, top_row_sum - curr_top_sum));
            bottom_row_sum += grid[1][i];
        }

        return ans;
    }
};