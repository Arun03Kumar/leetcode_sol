class Solution {
public:
    int small_or_equal(int n, vector<int> v) {
        int count = 0;
        for(auto &x : v) {
            if(x <= n) count++;
        }
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = -1;
        while(l <= r) {
            int mid = (l+r) / 2;
            int count = small_or_equal(mid, nums);
            if(count > mid) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};