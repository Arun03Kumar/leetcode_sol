class Solution {
public:
    int recursion(string &s1, string &s2, int i, int j) {
        if(i >= s1.size() || j >= s2.size()) return 0;

        int take = 0;
        if(s1[i] == s2[j]) {
            take = 1 + recursion(s1, s2, i + 1, j + 1);
        }
        int skip1 = recursion(s1, s2, i + 1, j);
        int skip2 = recursion(s1, s2, i, j + 1);

        return max({take, skip1, skip2});
    }

    int memoization(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if(i >= s1.size() || j >= s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(s1[i] == s2[j]) {
            take = 1 + memoization(s1, s2, i + 1, j + 1, dp);
        }
        int skip1 = memoization(s1, s2, i + 1, j, dp);
        int skip2 = memoization(s1, s2, i, j + 1, dp);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return recursion(text1, text2, 0, 0);

        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoization(text1, text2, 0, 0, dp);
    }
};