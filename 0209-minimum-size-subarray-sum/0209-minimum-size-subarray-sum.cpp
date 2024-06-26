class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, ans = INT_MAX;
        long long curr_sum = 0;
        while(r < nums.size()) {
            curr_sum += nums[r];
            // if(curr_sum >= target) {
            // }
            while(curr_sum >= target) {
                ans = min(ans, r - l + 1);
                curr_sum -= nums[l];
                l++;
            }       
            r++;     
        }
        return ans == INT_MAX ? 0 : ans;
    }
};