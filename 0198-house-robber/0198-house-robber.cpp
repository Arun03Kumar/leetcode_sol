class Solution {
public:
    int recursion(vector<int> &nums, int idx) {
        if(idx >= nums.size()) return 0;

        int a = nums[idx] + recursion(nums, idx + 2);
        int b = recursion(nums, idx + 1);

        return max(a, b);
    }

    int memoization(vector<int> &nums, int idx, vector<int> &dp) {
        if(idx >= nums.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int a = nums[idx] + memoization(nums, idx + 2, dp);
        int b = memoization(nums, idx + 1, dp);

        return dp[idx] = max(a, b);
    }

    int rob(vector<int>& nums) {
        // Approach 1: recursion

        // int a = recursion(nums, 0);
        // int b = recursion(nums, 1);

        // return max(a, b);


        // Approach 2: memoization

        vector<int> dp(nums.size() + 1, -1);

        dp[0] = memoization(nums, 0, dp);
        dp[1] = memoization(nums, 1, dp);

        return max(dp[0], dp[1]);
    }
};