class Solution {
public:
    // int recursion(vector<int> &nums, int idx) {
    //     if(idx >= nums.size()) return 0;

    // }

    int findNumberOfLIS(vector<int>& nums) {
        // in this we create a max LIS array as we do in LIS with bottom up approach, with extra count array which tells the number of ways we can create the current LIS.

        // in the last we need to add all the values which will give the max LIS value and also add the count of them in the answer.
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        vector<int> count(n + 1, 1);

        int max_lis = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(nums[j] >= nums[i]) continue;

                if(dp[i] == 1 + dp[j]) {
                    count[i] += count[j];
                }

                if(dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }

            }

            max_lis = max(max_lis, dp[i]);
        }

        // cout << max_lis;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == max_lis) {
                ans += count[i];
            }
        }

        return ans;
    }
};