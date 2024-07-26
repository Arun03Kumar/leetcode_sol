class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // we create a ans variable initialized with 0 means all bits will be 0
        // we are finding the last bit by anding with 1 and pasting it at the (32 - i)th position, we do this by ORing with left shift
        // bits positions are followed as 31, 30, 29, ...., 3, 2, 1
        // n&1 krne se hme right most bit mil jaegi, usko hmko paste krna h (32 - i)th  position pr uske liye 31-i times left shift krenge
        // ar phir OR kr denge so if bit hme 0 mili thi to 0OR0 is 0 and 0|1 is 1.

        uint32_t ans = 0;
        for(int i = 0; i < 32; i++) {
            int bit = (n & 1);
            n >>= 1;

            ans = ans | (bit << (31 - i));
        }

        return ans;
    }
};