class Solution {
public:
    bool recursion(vector<int> &nums, int idx) {

        if(idx >= nums.size()) return true;

        bool a = false, b = false, c = false;
        if(idx + 1 < nums.size() && nums[idx + 1] == nums[idx]) {
            a = recursion(nums, idx + 2);
        }

        if(idx + 2 < nums.size() && nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
            b = recursion(nums, idx + 3);
        }

        if(idx + 2 < nums.size() && nums[idx] + 1 == nums[idx + 1] && nums[idx + 1] + 1 == nums[idx + 2]) {
            c = recursion(nums, idx + 3);
        }

        return a || b || c;

    }
    bool validPartition(vector<int>& nums) {
        return recursion(nums, 0);
    }
};