class Solution {
public:
    int helper(int n, vector<int> &dp) {
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];

        if(n == 0) return dp[0] = 1;

        return dp[n] = (helper(n - 1, dp) + helper(n - 2, dp));
    }
    int climbStairs(int n) {
        vector<int> dp(46, -1);
        helper(n, dp);
        return dp[n];
    }
};