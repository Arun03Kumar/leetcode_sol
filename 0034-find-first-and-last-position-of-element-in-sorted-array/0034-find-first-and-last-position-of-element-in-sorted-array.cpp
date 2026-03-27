class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = lower_bound(begin(nums), end(nums), target);
        auto it2 = upper_bound(begin(nums), end(nums), target);

        vector<int> ans = {-1, -1};
        if(it != end(nums) && *it == target) {
            ans[0] = it - begin(nums);
            ans[1] = it2 - begin(nums) - 1;
        }
        return ans;
    }
};