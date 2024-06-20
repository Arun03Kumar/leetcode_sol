class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // what we did is basically use two pointer from both ends compare there absolute values which one is greater will have a higher square so put that square in the last of ans array, so we fill the answer array from last.
        int l = 0, r = nums.size() - 1, p = nums.size() - 1;
        vector<int> ans(nums.size());
        while(l <= r) {
            if(abs(nums[l]) < abs(nums[r])) {
                ans[p] = nums[r] * nums[r];
                p--;
                r--;
            }
            else {
                ans[p] = nums[l] * nums[l];
                p--;
                l++;
            }
        }
        return ans;
    }
};