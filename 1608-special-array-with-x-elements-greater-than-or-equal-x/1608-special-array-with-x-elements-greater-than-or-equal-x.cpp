class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        int l = 0, r = n;

        while(l <= r) {
            int mid = l + (r - l) / 2;

            int greater_than_mid = lower_bound(begin(nums), end(nums), mid) - begin(nums);
            int count = n - greater_than_mid;

            if(count == mid) {
                return mid;
            }
            else if(count > mid) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }

        }

        return -1;
    }
};