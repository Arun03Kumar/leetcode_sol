class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        // Approach 1: using prefix sum
        // since array is sorted so if we are at index i then if we subtract values less than index i we will get positive numbers, simillarly if we subtract values which are present at indexes greater than i, we will get negative numbers
        // but abs(a - b) == abs(b - a) /
        // so if we can rearrange then:
        // lets we are at index i
        // abs(nums[i] - nums[0]) + abs(nums[i] - nums[1]) + ... + ans(nums[i] - nums[i - 1])  => for all this we will get positive val
        // abs(nums[i] - nums[i + 1]) + abs(nums[i] - nums[i + 2]) + ... + abs(nums[i] - nums[n - 1]) => these all we can rearrane as
        // nums[i + 1] - nums[i] + nums[i + 2] - nums[i] + ... + nums[n - 1] - nums[i]
        // when we combine both we can see that total sum is equivalent to 
        // nums[i] * i - sum(nums[0] to nums[i - 1]) + sum(nums[i + 1] to nums[n -  1]) - nums[i] * (n - i - 1)
        // we can use prefix sum to calculate the sum

        int n = nums.size();
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            int s1 = nums[i] * i;
            int s2 = prefix[i] - nums[i];
            int s3 = nums[i] * (n - i - 1);
            int s4 = prefix[n - 1] - prefix[i];

            ans[i] = s1 - s2 + s4 - s3;
        }

        return ans;
    }
};