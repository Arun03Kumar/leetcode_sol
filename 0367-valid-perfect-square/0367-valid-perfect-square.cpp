class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num / 2 + 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            long long mul = mid * 1LL * mid * 1LL;
            if(mul == num) {
                return true;
            }
            else if(mul > num) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
};