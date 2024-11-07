class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // we know 'and' of number can only be 1 when all positions have the bit as 1
        // and since max number is upto 10^7 that can be easily fit into integer, and integers are stored in 32 bits
        // so we need to just find out how many integers have highest number of ones at each bit from 1 to 32
        // 1 0 0 1
        // 0 1 0 0
        // 1 1 1 1
        // 0 1 1 0
        // in above we can see at first bit position only 2 numbers have 1 bit so we can include them in one combination that will give & of each greater than 1
        // similarly if we see at bit position 3 we can see 3 numbers have 1 bit there so we can include them into one combination and then our ans wil updated to 3.
        int ans = 1;
        for(int i = 0; i < 32; i++) {
            int curr = 0;
            for(int &x: candidates) {
                if(x & (1 << i)) curr++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};