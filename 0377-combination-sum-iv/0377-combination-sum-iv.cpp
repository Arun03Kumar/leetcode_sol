class Solution {
public:
    int recursion(vector<int>& nums, int rem_sum, int idx) {
        if(idx >= nums.size()) return 0;

        if(rem_sum == 0) return 1;
        
        int take = 0;
        if(take <= rem_sum) {
            take = recursion(nums, rem_sum - nums[idx], 0);
        }

        int skip = recursion(nums, rem_sum, idx + 1);

        return take + skip;
    }

    int memoization(vector<int> &nums, vector<vector<int>> &dp, int rem_sum, int idx) {
        if(idx >= nums.size()) return 0;

        if(rem_sum == 0) return dp[idx][rem_sum] = 1;

        if(dp[idx][rem_sum] != -1) return dp[idx][rem_sum];

        int take = 0;
        if(nums[idx] <= rem_sum) {
            take = memoization(nums, dp, rem_sum - nums[idx], 0);
        }

        int skip = memoization(nums, dp, rem_sum, idx + 1);

        return dp[idx][rem_sum] = take + skip;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // return recursion(nums, target, 0);


        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return memoization(nums, dp, target, 0);
    }
};