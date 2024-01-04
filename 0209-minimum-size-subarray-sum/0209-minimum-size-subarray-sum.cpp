class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, ans = INT_MAX, sum = 0;
        while(j < nums.size()) {
            // while(sum < target && j < nums.size()) {
            //     sum += nums[j++];
            // }
            sum += nums[j];
            while(sum >= target && i < nums.size()) {
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};