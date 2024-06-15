class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_elem = 0;
        for(int x: nums) max_elem = max(max_elem, x);
        int l = 0, r = 0;
        long long ans = 0;
        unordered_map<int, int> ump;
        while(r < nums.size()) {
            ump[nums[r]]++;
            while(ump[max_elem] >= k) {
                ans += (nums.size() - r);
                ump[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};