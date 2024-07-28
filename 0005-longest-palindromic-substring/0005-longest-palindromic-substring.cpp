class Solution {
public:
    bool is_palindrome_recursion(string &s, int i, int j) {
        if(i >= j) return true;

        if(s[i] == s[j]) {
            return is_palindrome_recursion(s, i + 1, j - 1);
        }

        return false;
    }

    int is_palindrome_memoization(string &s, int i, int j, vector<vector<int>> &dp) {

        if(i >= j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = is_palindrome_memoization(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = 0;

    }

    string longestPalindrome(string s) {
        // find all substrings and check if it is palindrome maintain the length of substring and starting point.


        // int max_length = INT_MIN;
        // int starting_idx = -1;

        // for(int i = 0; i < s.size(); i++) {
        //     for(int j = 0; j < s.size(); j++) {

        //         if(is_palindrome_recursion(s, i, j) == true) {

        //             if(j - i + 1 > max_length) {

        //                 max_length = j - i + 1;
        //                 starting_idx = i;

        //             }

        //         }

        //     }
        // }

        // return s.substr(starting_idx, max_length);


        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        int max_length = INT_MIN;
        int starting_idx = -1;

        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < s.size(); j++) {

                if(is_palindrome_memoization(s, i, j, dp) == true) {

                    if(j - i + 1 > max_length) {
                        max_length = j - i + 1;
                        starting_idx = i;
                    }

                }

            }
        }

        return s.substr(starting_idx, max_length);

    }
};