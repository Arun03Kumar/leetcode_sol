class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix_sum(n);
        // partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
        prefix_sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            // int left_sum = i == 0 ? 0 : prefix_sum[i - 1];
            // int right_sum = i == n - 1 ? 0 : prefix_sum[n - 1] - prefix_sum[i];
            int left_sum, right_sum;
            if(i == 0) left_sum = 0;
            else left_sum = prefix_sum[i - 1];

            if(i == n - 1) right_sum = 0;
            else {
                right_sum = prefix_sum[n - 1] - prefix_sum[i];
            }

            if(left_sum == right_sum) return i;
        }

        return -1;
    }
};