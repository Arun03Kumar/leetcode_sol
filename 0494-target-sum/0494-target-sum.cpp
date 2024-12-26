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

    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(nums, target, 0, 0);
    }
};