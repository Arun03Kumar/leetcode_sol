class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return 0;

        sort(begin(nums), end(nums));

        int one = nums[n - 1] - nums[2];
        int two = nums[n - 2] - nums[1];
        int three = nums[n - 3] - nums[0];
        return min({one, two, three});
    }
};