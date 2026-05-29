class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int curr_sum = 0;

        for(int i = 0; i < n; i++) {
            if(curr_sum + nums[i] < nums[i]) {
                curr_sum = nums[i];
            }
            else {
                curr_sum += nums[i];
            }

            ans = max(ans, curr_sum);
        }
        
        return ans;
    }
};