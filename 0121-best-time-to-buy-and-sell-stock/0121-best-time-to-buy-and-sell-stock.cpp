class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min_price = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            int sell = prices[i];
            int profit = sell - min_price;
            ans = max(ans, profit);
            min_price = min(min_price, prices[i]);
        }
        return ans;
    }
};