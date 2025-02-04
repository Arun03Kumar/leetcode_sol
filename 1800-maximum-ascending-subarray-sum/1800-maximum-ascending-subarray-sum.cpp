class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0], temp = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                temp += nums[i];
            }
            else {
                temp = nums[i];
            }

            ans = max(ans, temp);
        }

        return ans;
    }
};