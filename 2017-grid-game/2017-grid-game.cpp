class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> prefix(2, vector<long long>(n, 0));
        prefix[0][0] = grid[0][0];
        prefix[1][0] = grid[1][0];

        for(int i = 1; i < n; i++) {
            prefix[0][i] = prefix[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < n; i++) {
            prefix[1][i] = prefix[1][i - 1] + grid[1][i];
        }

        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            long long top = (i == n - 1) ? 0 : prefix[0][n - 1] - prefix[0][i];
            long long bottom = (i == 0) ? 0 : prefix[1][i - 1];

            ans = min(ans, max(top, bottom));
        }

        return ans;
    }
};