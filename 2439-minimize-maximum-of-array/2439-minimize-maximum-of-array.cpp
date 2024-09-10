class Solution {
public:
    bool is_max(vector<int> &nums, int max_val) {
        vector<long long> arr(nums.begin(), nums.end());

        int n = arr.size();

        for(int i = 0; i < n - 1; i++) {
            if(arr[i] > max_val) return false;
            long long buffer = max_val - arr[i];
            arr[i + 1] -= buffer;
        }

        return arr[n - 1] <= max_val;
    }

    int minimizeArrayValue(vector<int>& nums) {
        // consider a max_value and for each element check if how much it is needed to be the max_value (e.g if element is 3 and max_element is 5 then we need 2) it means we can increase 2 and then i+1th element should decrease by 2.
        // if decreasing 2 is still greater than max then the considered max is not the greatest in the array
        // for finding the max_element we could use binary search

        int n = nums.size();

        int l = 1, r = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(is_max(nums, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};