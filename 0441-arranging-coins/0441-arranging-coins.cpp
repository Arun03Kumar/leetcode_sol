class Solution {
public:
    long long naturalSum(int x) {
        long long ans = x * 1LL * (x + 1) / 2;
        return ans;
    }

    int arrangeCoins(int n) {
        int l = 1, r = n;
        int ans = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(naturalSum(mid) <= n) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};