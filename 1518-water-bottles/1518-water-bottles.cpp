class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, curr_empty = numBottles;
        while(curr_empty >= numExchange) {
            int exchanged = curr_empty / numExchange;
            ans += exchanged;
            curr_empty = exchanged + (curr_empty % numExchange);
        }
        return ans;
    }
};