class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // if(k <= 0) return 0;
        int l = 0, r = 0;
        long curr_product = 1, ans = 0;
        while(r < nums.size()) {
            curr_product *= nums[r];
            while(l <= r && curr_product >= k) {
                curr_product /= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
};