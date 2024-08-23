class Solution {
public:
    int recursion(int n, int current_As, int As_in_clipboard) {
        if(current_As == n) return 0;
        if(current_As > n) return 100000;

        // here wew just paste what is present in the clipboard
        int paste = 1 + recursion(n, current_As + As_in_clipboard, As_in_clipboard);

        // here we are copying fist then paste so clipboard now contains the same As as in current_As.
        int copy_then_paste = 1 + 1 + recursion(n, current_As * 2, current_As);

        return min(paste, copy_then_paste);
    }

    int memoization(int n, vector<vector<int>> &dp, int current_As, int As_in_clipboard) {
        if(current_As == n) return 0;
        if(current_As > n) return 100000;

        if(dp[current_As][As_in_clipboard] != -1) return dp[current_As][As_in_clipboard];

        int paste = 1 + memoization(n, dp, current_As + As_in_clipboard, As_in_clipboard);

        int copy_then_paste = 1 + 1 + memoization(n, dp, current_As * 2, current_As);

        return dp[current_As][As_in_clipboard] = min(paste, copy_then_paste);
    }

    int minSteps(int n) {
        if(n == 1) return 0;
        
        // Approach 1: recursion
        // we have to copy first hence adding 1 in return.
        // in the start there is 1 A, and in clipboard there is also 1 A.
        // return 1 + recursion(n, 1, 1);


        // Approach 2: memoization
        // vector<vector<int>> dp(1001, vector<int>(1001, -1));
        // return 1 + memoization(n, dp, 1, 1);


        // Approach 3: bottom up + Greedy
        // if n == 30 then if we copy the 15 As and paste then it will take less operations hence we are going greedly here.
        // we are filling it bottom up
        // we are finding a factor which is half if it is not odd then we are reducing one till it gets the value;
        // ex. n == 27 -> n/2 = 13 will be factor but it is not fully divisible hence, 13-1 = 12 but still we cant divide 27 with 12 hence recude till 9.
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 0;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {

            int factor = i / 2;
            while(factor >= 1) {

                if(i % factor == 0) {
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    dp[i] = dp[factor] + copy + paste;
                    break;
                }
                else {
                    factor--;
                }
            }
        }

        return dp[n];
    }
};