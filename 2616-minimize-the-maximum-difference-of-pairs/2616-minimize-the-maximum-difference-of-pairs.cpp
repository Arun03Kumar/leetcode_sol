class Solution {
public:
    bool check(vector<int> arr, int p, int mid) {
        int cnt = 0, i = 0;
        while(i < arr.size() - 1) {
            if(abs(arr[i] - arr[i + 1]) <= mid) {
                cnt++;
                i += 2;
            }
            else {
                i += 1;
            }
            if(cnt == p)
                return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0) return 0;
        sort(nums.begin(), nums.end());
        int low = 0, high = 1e9, ans = 1e9;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};