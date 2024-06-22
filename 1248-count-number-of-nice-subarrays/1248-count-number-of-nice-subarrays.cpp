class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, mid = 0, r = 0;
        int odd = 0, ans = 0;
        while(r < nums.size()) {
            if(nums[r] % 2 == 1) {
                odd++;
            }
            while(odd > k) {
                if(nums[l] % 2 == 1)
                    odd--;
                l++;
                mid = l;
            }
            if(odd == k) {
                while(nums[mid] % 2 == 0) mid++;
                ans += (mid - l + 1);
            }
            r++;
        }
        return ans;
    }
};