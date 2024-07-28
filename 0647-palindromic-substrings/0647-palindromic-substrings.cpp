class Solution {
public:
    int is_palindrome_memoization(string &s, vector<vector<int>> &dp, int i, int j) {

        if(i >= j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = is_palindrome_memoization(s, dp, i + 1, j - 1);
        }

        return dp[i][j] = 0;

    }
    int countSubstrings(string s) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        int count = 0;

        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                
                if(is_palindrome_memoization(s, dp, i, j) == 1) {
                    count++;
                }

            }
        }

        return count;
    }
};