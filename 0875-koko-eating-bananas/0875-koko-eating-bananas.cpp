class Solution {
public:
    bool check(vector<int> arr, int h, int k) {
        long long tot_hours = 0;
        for(int x: arr) {
            if(x % k == 0)
                tot_hours += x / k;
            else
                tot_hours += x / k + 1;
            // tot_hours += ceil(x / k);
        }
        return tot_hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ = -1;
        for(int x: piles) {
            max_ = max(max_, x);
            // sum += x;
        }
        int low = 1, high = max_, ans = max_;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(piles, h, mid)) {
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