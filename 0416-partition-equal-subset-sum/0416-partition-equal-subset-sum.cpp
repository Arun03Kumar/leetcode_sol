class Solution {
public:
    bool recursion(vector<int> &nums, int rem_sum, int idx) {
        if(rem_sum == 0) return true;
        if(rem_sum < 0) return false;

        if(idx >= nums.size()) return false;

        bool a = recursion(nums, rem_sum - nums[idx], idx + 1);
        bool b = recursion(nums, rem_sum, idx + 1);

        return a || b;
    }

    int memoization(vector<int> &nums, int rem_sum, int idx, vector<vector<int>> &dp) {

        if(rem_sum == 0) return 1;
        if(idx == 0) return (nums[idx] == rem_sum);

        if(dp[idx][rem_sum] != -1) return dp[idx][rem_sum];

        bool a = false;
        if(nums[idx] <= rem_sum)
            a = memoization(nums, rem_sum - nums[idx], idx - 1, dp);
            
        bool b = memoization(nums, rem_sum, idx - 1, dp);

        return dp[idx][rem_sum] = (a || b);

    } 

    bool canPartition(vector<int>& nums) {

        //  Approach 1: recursion
        // first of all we find the sum of the given array if it is odd then we can't divie the given array into two equal sum subsets.
        // if sum is even it means we can divide it into equal part. so we just have to find that can we create a subset with sum as total_sum_array / 2.

        int arr_sum = 0;
        for(int x: nums) {
            arr_sum += x;
        }

        if(arr_sum % 2 == 1) return false;
        // return recursion(nums, arr_sum / 2, 0);

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(arr_sum + 1, -1));
        return memoization(nums, arr_sum / 2, n - 1, dp);
    }
};