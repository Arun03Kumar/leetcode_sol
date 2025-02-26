class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = nums[0], currSum = nums[0];
        for(int i = 1; i < n; i++) {
            currSum = max(nums[i], currSum + nums[i]); // it is like asking question that we should start a new subarray from current element(nums[i]) or we should continue from previous subarray by adding current into prev
            maxSum = max(currSum, maxSum);
        }

        int minSum = nums[0];
        currSum = nums[0];
        for(int i = 1; i < n; i++) {
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }

        return max(maxSum, abs(minSum));
    }
};
