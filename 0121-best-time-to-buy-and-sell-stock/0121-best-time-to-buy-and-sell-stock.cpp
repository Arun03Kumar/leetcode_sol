class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 0, maxProfit = 0;
        while(r < prices.size()) {
            if(prices[r] > prices[l]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            }
            else 
                l = r;
            r++;
        }
        return maxProfit;
    }
};