class Solution {
public:
    int recursion(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        int ans = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++) {
            ans = min(ans, 1 + recursion(n - i * i));
        }


        return ans == INT_MAX ? 0 : ans;
    }

    int memoization(int n, vector<int> &dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for(int i = 1; i <= sqrt(n); i++) {
            ans = min(ans, 1 + memoization(n - i * i, dp));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        // return recursion(n) - 1;

        vector<int> dp(n + 1, -1);
        return memoization(n, dp) - 1;
    }
};