class Solution {
public:
    int reverse(int x) {
        // if we multiply any number and their resultant is become greater than INT_MAX then we have to return 0
        // but we can do that directly because in that case we have to multiply the number and store than in long long but we can't to it here
        // since we are only multiplying each time by 10, so we can say that
        // a * 10 > INT_MAX or a > INT_MAX / 10 both are same
        // a * 10 < INT_MIN or a < INT_MIN / 10

        int ans = 0;
        // if we do x > 0 then that will not work for negative numbers
        while(x != 0) {
            int digit = x % 10;

            if(ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }
            
            ans = ans * 10 + digit;
            x /= 10;
        }

        return ans;
    }
};