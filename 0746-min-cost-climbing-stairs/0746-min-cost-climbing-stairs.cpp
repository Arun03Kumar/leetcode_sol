class Solution {
public:
    int helper(vector<int> &cost, int i, vector<int> &dp) {
        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int a = cost[i] + helper(cost, i + 1, dp);
        int b = cost[i] + helper(cost, i + 2, dp);
        return dp[i] = min(a, b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, -1);
        dp[0] = helper(cost, 0, dp);
        dp[1] = helper(cost, 1, dp);
        return min(dp[0], dp[1]);
        // return min(helper(cost, 0, dp), helper(cost, 1, dp));
    }
};