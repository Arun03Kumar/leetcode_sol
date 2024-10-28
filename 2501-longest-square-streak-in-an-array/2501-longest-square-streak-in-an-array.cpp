class Solution {
public:
    int recursion(vector<int> &nums, int idx, int prev) {
        if(idx >= nums.size()) return 0;

        int take = 0;
        if(prev == -1 || prev * 1LL * prev * 1LL == nums[idx]) {
            take = 1 + recursion(nums, idx + 1, nums[idx]);
        }
    
        int skip = recursion(nums, idx + 1, prev);

        return max(take, skip);
    }

    int memo(vector<int> &nums, int idx, int prev, unordered_map<int, unordered_map<int, int>> &dp) {
        if(idx >= nums.size()) return 0;

        if(dp.count(idx) && dp[idx].count(prev)) return dp[idx][prev];

        int take = 0;
        if(prev == -1 || prev * 1LL * prev * 1LL == nums[idx]) {
            take = 1 + memo(nums, idx + 1, nums[idx], dp);
        }

        int skip = memo(nums, idx + 1, prev, dp);

        return dp[idx][prev] = max(take, skip);
    }

    int longestSquareStreak(vector<int>& nums) {
        // Approach 1: recursion
        // sort(begin(nums), end(nums));
        // int x = recursion(nums, 0, -1);
        // return x <= 1 ? -1 : x;

        // Approach 2: Memoization
        // this wont work because prev*prev can be very large number
        // sort(begin(nums), end(nums));
        // int n = nums.size();
        // // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // unordered_map<int, unordered_map<int, int>> dp;
        // int x = memo(nums, 0, -1, dp);
        // return x <= 1 ? -1 : x;

        // Approach 3:
        int n = nums.size();
        sort(begin(nums), end(nums));
        unordered_map<int, int> streak;
        int ans = 0;

        for(int &x: nums) {
            int sqt = sqrt(x);
            if(sqt * sqt == x && streak.find(sqt) != streak.end()) {
                streak[x] = streak[sqt] + 1;
                ans = max(ans, streak[x]); 
            }
            else {
                streak[x] = 1;
            }
        }

        return ans <= 1 ? -1 : ans;
    }
};