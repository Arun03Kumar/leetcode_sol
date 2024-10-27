class Solution {
public:
    int totalMoney(int n) {
        // Approach 1: simulation
        // start with initial money then for each day in that week increase that amount by one and at the last increse the initial money
        // but when number of remaining days are smaller than 7 hence to tackle that case use min(n, 7)
        
        int initial_monday = 1;
        int ans = 0;

        while(n > 0) {
            int money = initial_monday;
            for(int i = 1; i <= min(n, 7); i++) {
                ans += money;
                money++;
            }

            n -= 7;
            initial_monday++;
        }

        return ans;
    }
};