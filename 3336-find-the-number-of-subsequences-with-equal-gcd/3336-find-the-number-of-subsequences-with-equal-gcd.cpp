class Solution {
public:
    const int M = 1e9 + 7;
    typedef long long ll;
    vector<vector<vector<int>>> dp;

    int recursion(vector<int> &nums, int idx, int gcd1, int gcd2) {
        if(idx >= nums.size()) {
            if(gcd1 == gcd2) return 1;
            return 0;
        }

        int seq1 = recursion(nums, idx + 1, __gcd(gcd1, nums[idx]), gcd2);
        int seq2 = recursion(nums, idx + 1, gcd1, __gcd(gcd2, nums[idx]));
        int skip = recursion(nums, idx + 1, gcd1, gcd2);

        return (seq1 % M + seq2 % M + skip % M) % M;
    }

    int memoization(vector<int> &nums, int idx, int gcd1, int gcd2) {
        if(idx >= nums.size()) {
            if(gcd1 == gcd2 && gcd1 != 0) return 1;
            return 0;
        }

        if(dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2];
        
        ll seq1 = memoization(nums, idx + 1, __gcd(gcd1, nums[idx]), gcd2);
        ll seq2 = memoization(nums, idx + 1, gcd1, __gcd(gcd2, nums[idx]));
        ll skip = memoization(nums, idx + 1, gcd1, gcd2);

        return dp[idx][gcd1][gcd2] = (seq1 % M + seq2 % M + skip % M) % M;
    }

    int subsequencePairCount(vector<int>& nums) {
        // return recursion(nums, 0, 0, 0) - 1;

        int maxVal = *max_element(nums.begin(), nums.end());;
        dp.resize(nums.size(), vector<vector<int>>(maxVal + 1, vector<int>(maxVal + 1, -1)));
        return memoization(nums, 0, 0, 0) % M;
    }
};