class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // we are precomputing the power of 2 till value 2^n, and using that.
        // first sort the array, and start from both ends if the sum of both ends are grater than target it means right element can not provide the sum hence go to previous element, and continue this.
        int M = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, ans = 0;

        vector<int> power(nums.size());
        power[0] = 1;
        for(int i = 1; i < nums.size(); i++) {
            power[i] = (power[i - 1] * 2) % M;
        }
        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                ans = ans % M + (power[r - l]) % M;
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};