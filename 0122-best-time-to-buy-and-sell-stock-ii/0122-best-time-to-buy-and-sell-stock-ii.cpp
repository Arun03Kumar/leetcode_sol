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
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return memoization(prices, 0, 0, dp);
    }
};