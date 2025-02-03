class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 1, ans2 = 1;
        int ans = -1;

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i]) ans1++;
            else {
                ans = max(ans1, ans);
                ans1 = 1;
            }
        }

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] > nums[i]) ans2++;
            else {
                ans = max(ans2, ans);
                ans2 = 1;
            }
        }

        return max({ans, ans1, ans2});
    }
};