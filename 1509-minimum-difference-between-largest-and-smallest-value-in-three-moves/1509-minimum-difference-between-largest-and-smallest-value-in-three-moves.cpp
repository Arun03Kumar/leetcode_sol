class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        else {
            sort(nums.begin(), nums.end());
            int l = nums[nums.size() - 1] - nums[3];
            int r = nums[nums.size() - 4] - nums[0];
            int l1 = nums[nums.size() - 3] - nums[1];
            int r1 = nums[nums.size() - 2] - nums[2];
            return min(l, min(r, min(l1, r1)));
        }
    }
    
};