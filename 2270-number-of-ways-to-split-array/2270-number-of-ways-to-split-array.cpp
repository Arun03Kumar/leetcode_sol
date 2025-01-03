class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(begin(nums), end(nums), 0LL);

        int ans = 0;
        long long curr_sum = 0;

        for(int i = 0; i < n - 1; i++) {
            curr_sum += nums[i];
            long long rem_sum = sum - curr_sum;
            if(curr_sum >= rem_sum) ans++;
        }

        return ans;
    }
};