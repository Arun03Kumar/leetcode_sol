class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // for size n there can be n * (n - 1) / 2 subarray can be formed
        int n = nums.size();

        int i = 0;
        long long ans = 0;
        while(i < n) {
            long long count = 0;
            if(nums[i] == 0) {
                while(i < n && nums[i] == 0) {
                    i++;
                    count++;
                }
            }
            else {
                i++;
            }

            ans += count * (count + 1) / 2;
        }

        return ans;
    }
};