class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0;
        unordered_map<int, int> ump;
        while(r < nums.size()) {
            ump[nums[r]]++;
            while(ump[nums[r]] > k) {
                ump[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};