class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(1LL * mid * mid == x * 1LL) return mid;
            else if(1LL * mid * mid < x) l = mid + 1;
            else r = mid - 1;
        }
        return l - 1;
    }
};