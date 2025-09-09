class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_price_so_far = prices[0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            ans = max(ans, prices[i] - min_price_so_far);
            min_price_so_far = min(min_price_so_far, prices[i]);
        }
        return ans;
    }
};