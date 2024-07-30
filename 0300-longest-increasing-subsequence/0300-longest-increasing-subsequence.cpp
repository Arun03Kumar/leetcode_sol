class Solution {
public:
    int recursion(vector<int> &nums, int idx, int prev) {
        if(idx >= nums.size()) return 0;

        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx]) {
            take = 1 + recursion(nums, idx + 1, idx);
        }

        int skip = recursion(nums, idx + 1, prev);

        return max(take, skip);
    }

    int memoization(vector<int> &nums, vector<vector<int>> &dp, int idx, int prev) {

        if(idx >= nums.size()) return 0;

        if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];

        int take = 0;
        if(prev == -1 || nums[prev] < nums[idx]) {
            take = 1 + memoization(nums, dp, idx + 1, idx);
        }

        int skip = memoization(nums, dp, idx + 1, prev);

        if(prev == -1) {
            return max(take, skip);
        }

        return dp[idx][prev] = max(take, skip);

    }

    int lengthOfLIS(vector<int>& nums) {
        // we also take care of previous idx, so that we can compare that which element we can take and which we can skip.

        // when we take we just add 1 to the answer and call on next idx with current idx as prev idx.
        //but if we skip the current element then prev idx will remains the same as what we had previously taken.

        // return recursion(nums, 0, -1);


        // Approach 2: memoization

        // since prev and idx is changing hence we need to create a 2d ap array
        // and we need to add check for all where prev == -1, so we need to take care for that

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(nums, dp, 0, -1);
        return dp[0][0];

    }
};