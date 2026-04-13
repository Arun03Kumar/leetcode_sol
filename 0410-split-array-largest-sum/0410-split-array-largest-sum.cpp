class Solution {
public:
    bool is_valid(vector<int> &nums, int mid, int k) {
        int count = 1, temp = 0;
        for(int x: nums) {
            if(temp + x <= mid) {
                temp += x;
            }
            else {
                count++;
                temp = x;
            }

            if(count > k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(begin(nums), end(nums));
        int r = accumulate(begin(nums), end(nums), 0);
        int ans = l;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int val = is_valid(nums, mid, k);
            if(val) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};