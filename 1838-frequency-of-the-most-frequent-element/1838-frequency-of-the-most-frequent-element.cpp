class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long l = 0, r = 0, max_win = 0;
        long long curr_sum = 0;
        while(r < nums.size()) {
            curr_sum += nums[r];
            while(curr_sum + k < nums[r] * (r - l + 1)) {
                curr_sum -= nums[l];
                l++;
            }
            max_win = max(max_win, r - l + 1);
            r++;
        }
        return max_win;
    }
};