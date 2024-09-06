class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool is_increasing = false;
        bool is_decreasing = false;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] < nums[i + 1]) {
                is_increasing = true;
            }

            if(nums[i] > nums[i + 1]) {
                is_decreasing = true;
            }
        }

        if(is_increasing && is_decreasing) return false;

        return true;
    }
};