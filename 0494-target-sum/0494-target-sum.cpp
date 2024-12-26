class Solution {
public:
    int recursion(vector<int> &nums, int target, int idx, int curr) {
        if(idx >= nums.size()) {
            if(curr == target) return 1;

            return 0;
        }

        int one = recursion(nums, target, idx + 1, curr + nums[idx]);
        int two = recursion(nums, target, idx + 1, curr - nums[idx]);

        return one + two;
    }

    int memoization(vector<int> &nums, int target, int idx, int curr, unordered_map<string, int> &dp) {
        if(idx >= nums.size()) {
            if(curr == target) return 1;
            
            return 0;
        }

        string s = to_string(idx) + '_' + to_string(curr);
        if(dp.find(s) != dp.end()) return dp[s];
    
        int one = memoization(nums, target, idx + 1, curr + nums[idx], dp);
        int two = memoization(nums, target, idx + 1, curr - nums[idx], dp);
        
        return dp[s] = one + two;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return recursion(nums, target, 0, 0);

        unordered_map<string, int> dp;
        return memoization(nums, target, 0, 0, dp);
    }
};