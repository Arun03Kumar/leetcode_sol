class Solution {
public:
    vector<int> countBits(int n) {
        // in an interval of 2^x to 2^(x+1) only change is the most significant bit and in othre places it is same as previous bits so we need to just find the offset.

        // watch the video to understand better or write binary representation till 16.
        vector<int> dp(n + 1, 0);

        int offset = 1;
        for(int i = 1; i <= n; i++) {
            if(offset * 2 == i) {
                offset = i;
            }

            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};