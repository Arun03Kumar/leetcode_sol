class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // to get the maximum xor of two number the bits should be flipped for each index.
        // e. 1010^0101 this will be maximum because this will give all 1s
        // in any other cases it will give less number of 1s because (0^0=0), (1^1=0), (0^1=1), (1^0=1)
        // but how to find the flip of a number?? we just can't simply invert using ~, because since number is stored in 32 bit so all MSBs will be inverted to 1s, eg. for 3 -> 000000011 -> (111111100) so this is not correct 
        // we want only 2 bits and flipped for number 3
        // but in question it is given that maximum number will be less than 2^maxbit, so we can create a mask of all 1s of length maxbit by (2^maxbit)-1 => this will give all 1s of length maxbit
        //eg. maxbit = 3 => (2^3)-1 => 7 => (111)
        // and to get the flipped version of a number we can simply take xor with all 1s it will give the flipped version of that number
        // eg. 1010^1111 => 0101 which is flipped
        // and we know that xor of two same numbers is 0, so to remove the xor of last number we can just xor with it from all xor

        int all_xor = 0;
        for(int &x: nums) all_xor ^= x;

        int n = nums.size();
        vector<int> ans;

        int mask = (1 << maximumBit) - 1;
        for(int i = n - 1; i >= 0; i--) {
            int k = (all_xor ^ mask);
            ans.push_back(k);
            all_xor ^= nums[i];
        }

        return ans;
    }
};