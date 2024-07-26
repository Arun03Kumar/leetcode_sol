class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0^0 -> 0, 0^1 -> 1, 1^0 -> 1, 1^1 -> 0
        // xor with the same number gives 0, and xor with the 0 gives the same number, also the order doesen't matter

        // we first do the xor of all numbers from 0 to n.
        // then we do the xor from the nums array, so at some point from nums 2 numbers would be xored and they will give 0, only one number which is not present in nums will remain.

        int xor_total = 0;
        for(int i = 0; i <= nums.size(); i++) {
            xor_total ^= i;
        }

        for(int i = 0; i < nums.size(); i++) {
            xor_total ^= nums[i];
        }

        return xor_total;
    }
};