class Solution {
public:
    int recursion(vector<int> &nums, int idx, int end) {

        if(idx > end) return 0;

        int a = nums[idx] + recursion(nums, idx + 2, end);
        int b = recursion(nums, idx + 1, end);

        return max(a, b);

    }
    
    int memoization(vector<int> &nums, int idx, int end, vector<int> &dp) {

        if(idx > end) return 0;

        if(dp[idx] != -1) return dp[idx];

        int a = nums[idx] + memoization(nums, idx + 2, end, dp);
        int b = memoization(nums, idx + 1, end, dp);

        return dp[idx] = max(a, b);
    }

    int rob(vector<int>& nums) {
        // Approach 1: Recursion
        // if we start from 0 then we can only go till n - 2 because n - 1 house will be adjecent to 0
        // simillarly if we start from 1 we can only go to the n - 1 houese because 0 house after n - 1 will be adjecent to the 1

        // int a = recursion(nums, 0, nums.size() - 2);
        // int b = recursion(nums, 1, nums.size() - 1); 

        // return max(a, b);  

        
        // Approach 2: memoization

        // if(nums.size() == 1) return nums[0];

        // vector<int> dp(nums.size() + 1, -1);
        // int a = memoization(nums, 0, nums.size() - 2, dp);
        // vector<int> dp2(nums.size() + 1, -1);
        // int b = memoization(nums, 1, nums.size() - 1, dp2);
        // return max(a, b);
        // return max(dp[0], dp[1]);


        // Approach 3: bottom up

        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        auto rob_range = [&](int start, int end) {
            vector<int> dp(end - start + 1, 0);
            dp[0] = nums[start];
            dp[1] = max(nums[start], nums[start + 1]);
            for (int i = 2; i <= end - start; ++i) {
                dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
            }
            return dp[end - start];
        };

        int max1 = rob_range(0, n - 2);
        int max2 = rob_range(1, n - 1);

        return max(max1, max2);


    }
};