class Solution {
public:
    int recursion(vector<int> &prices, int idx, char buy_or_sell) {
        if(idx >= prices.size()) return 0;

        int buy = 0, sell = 0;
        if(buy_or_sell == 'B') {
            int buy1 = -prices[idx] + recursion(prices, idx + 1, 'S');
            int skip = 0 + recursion(prices, idx + 1, 'B');
            buy = max(buy1, skip);
        } 
        else {
            int sell1 = prices[idx] + recursion(prices, idx + 1, 'B');
            int skip1 = 0 + recursion(prices, idx + 1, 'S');
            sell = max(sell1, skip1);
        }

        return max(buy, sell);
    }

    int memoization(vector<int> &prices, int idx, int buy_or_sell, vector<vector<int>> &dp) {
        if(idx >= prices.size()) return 0;

        if(dp[idx][buy_or_sell] != -1) return dp[idx][buy_or_sell];

        int buy = 0, sell = 0;

        if(buy_or_sell == 0) {
            int buy1 = -prices[idx] + memoization(prices, idx + 1, 1, dp);
            int skip_buy = 0 + memoization(prices, idx + 1, 0, dp);
            buy = max(buy1, skip_buy);
        }
        else {
            int sell1 = prices[idx] + memoization(prices, idx + 1, 0, dp);
            int skip_sell = 0 + memoization(prices, idx + 1, 1, dp);
            sell = max(sell1, skip_sell);
        }

        return dp[idx][buy_or_sell] = max(buy, sell);
    }

    int maxProfit(vector<int>& prices) {
        // for each element we have two options either buy on it or sell on it
        // but if we have previously bought then on the next element we can either sell or skip that element then sell on other
        // similarly if we have sell any item then on next item we can only buy or skip to buy on furthur element.
        // return recursion(prices, 0, 'B');

        // Approach 2: memoization
        // we can represent buy as 0 and sell as 1
        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return memoization(prices, 0, 0, dp);


        // Approach 3: bottom up / tabulation
        // bottom up is just copying pasting of memoization no need to think just change the variables

        // int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // dp[n][0] = dp[n][1] = 0;

        // for(int i = n - 1; i >= 0; i--) {
        //     for(int j = 0; j < 2; j++) {
                
        //         int buy = 0, sell = 0;
        //         if(j == 0) {
        //             int buy1 = -prices[i] + dp[i + 1][1];
        //             int buy_skip = 0 + dp[i + 1][0];
        //             buy = max(buy1, buy_skip);
        //         }
        //         else {
        //             int sell1 = prices[i] + dp[i + 1][0];
        //             int skip_sell = 0 + dp[i + 1][1];
        //             sell = max(sell1, skip_sell);
        //         }
                
        //         dp[i][j] = max(buy, sell);
        //     }
        // }

        // return dp[0][0];


        // Approach 4: space optimization
        // in the tabulation we can see that index i values are depends upon index i + 1 values in the dp array so we need only two variables to store the i + 1 index values and we will update it for each iteration

        int n = prices.size();
        int dp_0 = 0, dp_1 = 0;
        int curr_0 = 0, curr_1 = 0;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                
                int buy = 0, sell = 0;
                if(j == 0) {
                    int buy1 = -prices[i] + dp_1;
                    int buy_skip = 0 + dp_0;
                    buy = max(buy1, buy_skip);
                }
                else {
                    int sell1 = prices[i] + dp_0;
                    int skip_sell = 0 + dp_1;
                    sell = max(sell1, skip_sell);
                }
                
                if(j == 0) curr_0 = max(buy, sell);
                else curr_1 = max(buy, sell);
            }

            dp_0 = curr_0;
            dp_1 = curr_1;

        }

        return dp_0;
    }
};