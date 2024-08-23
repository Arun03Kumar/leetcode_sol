class Solution {
public:
    int findComplement(int num) {
        // Approach 1: find number of bits in the given number
        // for each bit we can xor with the 1 at the ith position, we know if we do xor with 1 then the bit gets flipped.
        // for each iteration we do (1 << i) so we are flipping ith bit in ith iteration.
        int number_of_bits = (int)(log2(num)) + 1;

        for(int i = 0; i < number_of_bits; i++) {
            num = num ^ (1 << i);
        } 

        return num;
    }
};