class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mx = INT_MAX, i = 0;
        while(i + k <= nums.size()) {
            mx = min(mx, nums[i + k - 1] - nums[i]);
            i++;
        }
        return mx;
    }
};