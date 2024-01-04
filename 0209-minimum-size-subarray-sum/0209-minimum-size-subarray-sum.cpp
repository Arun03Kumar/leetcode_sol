class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, ans = nums.size() + 1, sum = 0;
        while(j < nums.size()) {
            // while(sum < target && j < nums.size()) {
            //     sum += nums[j++];
            // }
            sum += nums[j++];
            while(sum >= target && i < nums.size()) {
                ans = min(ans, j - i);
                sum -= nums[i++];
            }
            j++;
        }
        if(ans == nums.size() + 1) return 0;
        return ans;
    }
};