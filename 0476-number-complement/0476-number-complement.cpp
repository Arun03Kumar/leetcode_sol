class Solution {
public:
    int findComplement(int num) {
        // Approach 1: find number of bits in the given number
        // for each bit we can xor with the 1 at the ith position, we know if we do xor with 1 then the bit gets flipped.
        // for each iteration we do (1 << i) so we are flipping ith bit in ith iteration.
        // int number_of_bits = (int)(log2(num)) + 1;

        // for(int i = 0; i < number_of_bits; i++) {
        //     num = num ^ (1 << i);
        // } 

        // return num;

        // Approach 2: instead of xoring at each iteration with 1 we can create a mask with all 1s and just do the xor with the given number.
        // (1 << number_of_bits) with this we can create number equal to 2^number_of_bits then if we subtract by 1 then we will get all 1s.
        // ex. lets number of bits is 3, so (1 << 3) will give 1000 which is equal to 8, and if we subtract 1 from it then 8 - 1 =7, which is 0111. all ones.
        int number_of_bits = (int)(log2(num)) + 1;

        unsigned int mask = (1U << number_of_bits) - 1;

        return num ^ mask;
    }
};