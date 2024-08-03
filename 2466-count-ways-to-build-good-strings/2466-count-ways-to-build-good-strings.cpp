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

        vector<int> dp(high + 1, -1);
        return memoization(low, high, zero, one, dp, 0);
    }
};