class Solution {
public:
    int find_val(vector<int> &nums, int idx, int val) {
        int i = lower_bound(begin(nums) + idx, end(nums), val) - begin(nums);

        if(i < nums.size() && nums[i] == val) return i;

        return -1;
    }

    int recursion(vector<int> &nums, int idx, int inc, vector<vector<int>> &dp) {

        if(dp[idx][inc] != -1) return dp[idx][inc];

        int curr_val = nums[idx] + inc;
        int temp = 1;

        int x = find_val(nums, idx + 1, curr_val + 1);
        if(x != -1) {
            temp = max(temp, 1 + recursion(nums, x, 0, dp));
        }

        int y = find_val(nums, idx + 1, curr_val);
        if(y != -1) {
            temp = max(temp, 1 + recursion(nums, y, 1, dp));
        }

        return dp[idx][inc] = temp;
    }

    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        sort(begin(nums), end(nums));
        int ans = 1;
        for(int i = 0; i < nums.size(); i++) {
            int x = recursion(nums, i, 0, dp);
            int y = recursion(nums, i, 1, dp);
            ans = max(ans, max(x, y));
        }
        return ans;
    }
};