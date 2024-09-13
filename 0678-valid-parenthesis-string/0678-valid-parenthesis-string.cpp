class Solution {
public:
    bool recursive(string &s, int idx, int open_count) {
        if(idx == s.size()) return open_count == 0;

        bool is_valid = false;
        if(s[idx] == '(') {
            is_valid |= recursive(s, idx + 1, open_count + 1);
        }
        else if(s[idx] == '*') {
            is_valid |= recursive(s, idx + 1, open_count + 1);
            is_valid |= recursive(s, idx + 1, open_count);
            if(open_count > 0) is_valid |= recursive(s, idx + 1, open_count - 1);  
        }
        else {
            if(open_count > 0) is_valid |= recursive(s, idx + 1, open_count - 1);
        }

        return is_valid;
    }

    bool memoization(string &s, vector<vector<int>> &dp, int idx, int open_count) {
        if(idx == s.size()) return open_count == 0;

        if(dp[idx][open_count] != -1) return dp[idx][open_count];

        bool is_valid = false;
        if(s[idx] == '(') {
            is_valid |= memoization(s, dp, idx + 1, open_count + 1);
        }
        else if(s[idx] == '*') {
            is_valid |= memoization(s, dp, idx + 1, open_count + 1);
            is_valid |= memoization(s, dp, idx + 1, open_count );
            if(open_count > 0) is_valid |= memoization(s, dp, idx + 1, open_count - 1);
        }
        else {
            if(open_count > 0) is_valid |= memoization(s, dp, idx + 1, open_count - 1);
        }

        return dp[idx][open_count] = is_valid;
    }

    bool checkValidString(string s) {
        // Approach 1: Recursive
        // return recursive(s, 0, 0);

        // Approach 2: Memoization
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return memoization(s, dp, 0, 0);
    }
};