class Solution {
public:
    int arrangeCoins(int n) {
        long long i = 1, ans = 0, count = 0;
        while((long long)count + i <= n) {
            ans++;
            count += i;
            i++;
        }

        return (int)ans;
    }
};