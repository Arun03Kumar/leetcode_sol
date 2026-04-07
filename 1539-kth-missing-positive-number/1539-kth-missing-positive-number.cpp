class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;

            int miss_vals = arr[mid] - 1 - mid;
            if(miss_vals < k) l = mid + 1;
            else r = mid - 1;
        }
        return l + k;
    }
};