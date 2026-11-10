class Solution {
public:
    int recursion(vector<int> &c, int n, int curr, vector<int> &dp) {
        if(curr == n) return 0;

        if(dp[curr] != -1) return dp[curr];

        int ans = INT_MAX;
        for(int i = 1; i <= 3; i++) {
            if(curr + i <= n) {
                int cost = c[curr + i - 1] + i * i; 
                ans = min(ans, cost + recursion(c, n, curr + i, dp));
            } 
        }
        return dp[curr] = ans;
    } 

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return recursion(costs, n, 0, dp);
    }
};