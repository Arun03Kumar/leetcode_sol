class Solution {
public:
    long long minEnd(int n, int x) {
        // first number in the array will always be x, because we want the AND to be x, and if we take any number less than 1 then there will be at least 1 bit 0 which will reduce the AND value.
        // but how to choose next number which gives the AND as x
        // if we take OR with the just next number it will give the next value which AND will be x, because just next number is greater with one bit so we want that bit for the next greater but we have to do the OR to the correct number
        // eg let x = 9 => 1001, next number is 10 => 1010
        // 1001 | 1010 => 1011(11) and if we take & of 11 with 9 it will be 9
        // 1001 & 1011 => 1001(9)
        long long ans = x;
        for(int i = 0; i < n - 1; i++) {
            ans = (ans + 1) | x;
        }
        return ans;
    }
};