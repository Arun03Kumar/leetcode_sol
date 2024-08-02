class Solution {
public:
    int recursion(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i >= nums1.size() || j >= nums2.size()) return 0;

        if(nums1[i] == nums2[j]) {
            return 1 + recursion(nums1, nums2, i + 1, j + 1);
        }

        return max(recursion(nums1, nums2, i + 1, j), recursion(nums1, nums2, i, j + 1));
    }

    int memoization(vector<int>& nums1, vector<int>& nums2, vector<vector<int>> dp, int i, int j) {

        if(i >= nums1.size() || j >= nums2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j]) {
            return dp[i][j] = 1 + memoization(nums1, nums2, dp, i + 1, j + 1);
        }

        int a = memoization(nums1, nums2, dp, i + 1, j);
        int b = memoization(nums1, nums2, dp, i, j + 1);
        return dp[i][j] = max(a, b);

    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // return recursion(nums1, nums2, 0, 0);

        // int m = nums1.size(), n = nums2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return memoization(nums1, nums2, dp, 0, 0);


        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {

                if(nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }

            }
        }
        
        return dp[m][n];
    }
};