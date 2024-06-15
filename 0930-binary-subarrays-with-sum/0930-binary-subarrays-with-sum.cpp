class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        long curr_sum = 0, ans = 0;
        while(r < nums.size()) {
            curr_sum += nums[r];
            while(l <= r && curr_sum > goal) {
                curr_sum -= nums[l];
                l++;
            }
            ans += r - l;
            r++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};