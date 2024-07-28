class Solution {
public:
    int recursion(string &s, int &n, int idx) {
        if(idx == n) return 1;

        if(s[idx] == '0') return 0;

        int taking_one_char = recursion(s, n, idx + 1);

        int taking_two_char = 0;
        if(idx + 1 < n && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            taking_two_char = recursion(s, n, idx + 2);
        }

        return taking_one_char + taking_two_char;
    }

    int memoization(string &s, vector<int> &dp, int &n, int idx) {
        if(dp[idx] != -1) return dp[idx];

        if(idx == n) return dp[idx] = 1;

        if(s[idx] == '0') return dp[idx] = 0;

        int take_one_char = memoization(s, dp, n, idx + 1);

        int take_two_char = 0;
        if(idx + 1 < n && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))) {
            take_two_char = memoization(s, dp, n, idx + 2);
        }

        return dp[idx] = take_one_char + take_two_char;
    }

    int numDecodings(string s) {
        int n = s.size();

        // if there is single 0 then we can not decode it
        // but 10 20 can be decoded.

        //we can call to the idx + 2 element only if first element at idx is 1 or 2, if it is 2 then we can only call if idx+i is less then 7

        // return recursion(s, n, 0);

        
        // Appraoch 2: memoization
        vector<int> dp(101, -1);
        memoization(s, dp, n, 0);
        return dp[0];
    // }
    }
};