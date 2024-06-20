class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x / 2 + 1, ans;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long mul = mid * 1LL * mid * 1LL;
            if(mul > x) {
                high = mid - 1;
            }
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};