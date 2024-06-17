class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = c;
        while(l <= r) {
            long long sum = l * l;
            sum += r * r;
            if(sum == c) {
                return true;
            }
            else if(sum > c) {
                r--;
            }
            else {
                l++;
            }
        }
        return false;
    }
};