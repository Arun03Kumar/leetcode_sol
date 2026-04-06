class Solution {
public:
    int find_sum(vector<int> &nums, int mid) {
        int s = 0;
        for(int x: nums) {
            s += (x + mid - 1) / mid;
        }
        return s;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(begin(nums), end(nums));
        int ans = r;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int val = find_sum(nums, mid);

            if(val <= threshold) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};