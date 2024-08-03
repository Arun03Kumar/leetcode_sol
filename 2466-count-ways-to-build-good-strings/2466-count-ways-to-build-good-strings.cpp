class Solution {
public:
    const int M = 1e9 + 7;
    int recursion(int low, int high, int zero, int one, string ans) {
        if(ans.size() > high) return 0;
        // if(ans.size() >= low && ans.size() <= high) return 1;

        string ones(one, '1');
        string zeros(zero, '0');

        string temp_zero = ans + zeros;
        string temp_one = ans + ones;

        int zero_take = 0, one_take = 0;
        if(temp_one.size() >= low && temp_one.size() <= high) {
            one_take = 1 + recursion(low, high, zero, one, temp_one);
        }
        else {
            one_take = recursion(low, high, zero, one, temp_one);
        }

        if(temp_zero.size() >= low && temp_zero.size() <= high) {
            zero_take = 1 + recursion(low, high, zero, one, temp_zero);
        }
        else {
            zero_take = recursion(low, high, zero, one, temp_zero);
        }

        return zero_take + one_take;
    }

    int memoization(int low, int high, int zero, int one, vector<int> &dp, int length) {

        if(length > high) return 0;

        if(dp[length] != -1) return dp[length];

        int should_add_one = 0;

        if(length >= low && length <= high) {
            should_add_one = 1;
        }

        int ones = memoization(low, high, zero, one, dp, length + one);
        int zeros = memoization(low, high, zero, one, dp, length + zero);

        return dp[length] = (should_add_one + ones + zeros) % M;

    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // return recursion(low, high, zero, one, "");

        // Approach 2: memoization
        // vector<int> dp(high + 1, -1);
        // return memoization(low, high, zero, one, dp, 0);


        // Approach 3: bottom up
        // first we form a dp array and fill it.
        // dp[i] tells number of good string of size i.
        // so we form all good strings and after sum it from low to high.

        // if adding x zeros or x ones to some string will form a good string then we can add from dp[i - x] so this will give ans for dp[i]

        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= high; i++) {
            if(i - zero >= 0) {
                dp[i] = (dp[i] % M + dp[i - zero] % M) % M;
            }
            if(i - one >= 0) {
                dp[i] = (dp[i] % M + dp[i - one] % M) % M;
            }
        }

        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans = (ans % M + dp[i] % M) % M;   
        }

        return ans;
    }
};