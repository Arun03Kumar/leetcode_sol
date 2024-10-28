class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n == 0) return false;

        // while(n != 1) {
        //     if(n % 4 == 0) n /= 4;
        //     else break;
        // }

        // return n == 1;

        // Approach 2:
        // we can find out that if a number is power of 2 by (n&(n-1) == 0)
        // if a number is power of 4 then then number - 1 will be divisible by 3
        // e.g. 16 -> (16 - 1) = 15 % 3 == 0
        if(n <= 0) return false;
        if((n & (n - 1)) == 0 && (n - 1) % 3 == 0) return true;
        return false;
    }
};