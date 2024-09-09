class Solution {
public:
    int recursion(vector<int>& nums, int idx) {
        if(idx >= nums.size() - 1) return 0;

        int temp = 10001;

        for(int i = 1; i <= nums[idx]; i++) {
            temp = min(temp, recursion(nums, idx + i));
        }
        return temp + 1;
    }

    int memoization(vector<int> &nums, int idx, vector<int> &dp) {

        if(idx >= nums.size() - 1) return 0;

        if(dp[idx] != -1) return dp[idx];

        int temp = 10001;
        for(int i = 1; i <= nums[idx]; i++) {
            temp = min(temp, memoization(nums, idx + i, dp));
        }

        return dp[idx] = (temp + 1);

    }
 
    int jump(vector<int>& nums) {
        // int ans = recursion(nums, 0);
        // return ans;

        int n = nums.size();
        vector<int> dp(n, -1);
        return memoization(nums, 0, dp);
    }
};