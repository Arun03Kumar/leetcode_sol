class Solution {
public:
    bool recursion(vector<int> &nums, int idx) {
        if(idx == nums.size() - 1) return true;
        if(idx >= nums.size()) return false;

        bool temp = false;
        for(int i = 1; i <= nums[idx]; i++) {
            temp |= recursion(nums, idx + i);
        }

        return temp;
    }

    bool memoization(vector<int> &nums, int idx, vector<int> &dp) {
        if(idx == nums.size() - 1) return true;
        if(idx >= nums.size()) return false;

        if(dp[idx] != -1) return dp[idx];

        // bool temp = false;
        for(int i = 1; i <= nums[idx]; i++) {
            // temp |= memoization(nums, idx + i, dp);
            if(memoization(nums, idx + i, dp)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        // Approach 1: Recursion
        // return recursion(nums, 0);


        // Approach 2: Memoization
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // return memoization(nums, 0, dp);


        // Approach 3: Bottom up
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] == true && nums[j] + j >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }
};