class Solution {
public:
    int recursive(vector<int> &coins, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int temp = recursive(coins, amount - coins[i]);
            if(temp != INT_MAX) {
                ans = min(ans, temp + 1);
            }
        }

        return ans;
    }

    int memoization(vector<int> &coins, int amount, vector<int> &dp) {

        if(amount < 0) return INT_MAX;
        if(amount == 0) return 0;

        if(dp[amount] != INT_MAX) return dp[amount];

        int min_coins = INT_MAX;
        for(int i = 0; i < coins.size(); i++) {
            int temp = memoization(coins, amount - coins[i], dp);
            if(temp >= 0 && temp < min_coins) {
                min_coins = temp + 1;
            }      
        }

        dp[amount] = (min_coins == INT_MAX) ? -1 : min_coins;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        
        //Approach 1: recursion or backtracking

        // int temp = recursive(coins, amount);
        // if(temp == INT_MAX) return -1;
        // else return temp;


        // Approach 2: memoization
        // vector<int> dp(amount + 1, INT_MAX);
        // memoization(coins, amount, dp);
        // return dp[amount] != INT_MAX ? dp[amount] : 0;

        // Approach 3: Bottom up

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {
            int temp = INT_MAX;
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] >= 0) {
                    if(dp[i - coins[j]] != INT_MAX)
                        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};