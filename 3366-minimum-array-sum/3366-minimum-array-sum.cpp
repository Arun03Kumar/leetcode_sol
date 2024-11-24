class Solution {
public:
    int recursion(vector<int> &nums, int k, int op1, int op2, int idx) {
        if(idx >= nums.size()) return 0;

        int ans = INT_MAX;

        if(op1 > 0) {
            int new_val = (nums[idx] + 1) / 2;
            int apply_op1 = new_val + recursion(nums, k, op1 - 1, op2, idx + 1);
            ans = min(ans, apply_op1);
        }

        if(op2 > 0 && nums[idx] >= k) {
            int new_val = nums[idx] - k;
            int apply_op2 = new_val + recursion(nums, k, op1, op2 - 1, idx + 1);
            ans = min(ans, apply_op2);
        }

        if(op1 > 0 && op2 > 0) {
            int new_val = (nums[idx] + 1) / 2;
            if(new_val >= k) new_val -= k;
            int apply_1_then_2 = new_val + recursion(nums, k, op1 - 1, op2 - 1, idx + 1);
            ans = min(ans, apply_1_then_2);
        }

        if(op1 > 0 && op2 > 0 && nums[idx] >= k) {
            int new_val = nums[idx] - k;
            new_val = (new_val + 1) / 2;
            int apply_2_then_1 = new_val + recursion(nums, k, op1 - 1, op2 - 1, idx + 1);
            ans = min(ans, apply_2_then_1);
        }

        ans = min(ans, nums[idx] + recursion(nums, k, op1, op2, idx + 1));

        return ans;
    }

    int dp[101][101][101];
    int memoization(vector<int> &nums, int k, int op1, int op2, int idx) {
        if(idx >= nums.size()) return 0;

        if(dp[idx][op1][op2] != -1) return dp[idx][op1][op2];

        int ans = INT_MAX;

        if(op1 > 0) {
            int new_val = (nums[idx] + 1) / 2;
            int apply_op1 = new_val + memoization(nums, k, op1 - 1, op2, idx + 1);
            ans = min(ans, apply_op1);
        }

        if(op2 > 0 && nums[idx] >= k) {
            int new_val = nums[idx] - k;
            int apply_op2 = new_val + memoization(nums, k, op1, op2 - 1, idx + 1);
            ans = min(ans, apply_op2);
        }

        if(op1 > 0 && op2 > 0) {
            int new_val = (nums[idx] + 1) / 2;
            if(new_val >= k) new_val -= k;
            int apply_1_then_2 = new_val + memoization(nums, k, op1 - 1, op2 - 1, idx + 1);
            ans = min(ans, apply_1_then_2);
        }

        if(op1 > 0 && op2 > 0 && nums[idx] >= k) {
            int new_val = nums[idx] - k;
            new_val = (new_val + 1) / 2;
            int apply_2_then_1 = new_val + memoization(nums, k, op1 - 1, op2 - 1, idx + 1);
            ans = min(ans, apply_2_then_1);
        }

        ans = min(ans, nums[idx] + memoization(nums, k, op1, op2, idx + 1));

        return dp[idx][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        // since at each index we have options so we can use dynamic programming
        // there are total five possibility at an index
        // 1. apply op1
        // 2. apply op2
        // 3. apply op1 then op2 if still number is greater than k
        // 4. apply op2 then op1
        // 5. skip any operation
        // for applying op2 we need to check if number is greater than k

        // return recursion(nums, k, op1, op2, 0);

        // Approach 2: memoization
        memset(dp, -1, sizeof(dp));
        return memoization(nums, k, op1, op2, 0);
    }
};