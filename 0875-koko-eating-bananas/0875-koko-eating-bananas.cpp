class Solution {
public:
    long long hoursNeeded(vector<int>& piles, int k) {
        long long total = 0;
        for (int x : piles) {
            // int temp = x / mid;
            // ans += (x % mid == 0 ? temp : temp + 1);
            total += (x + k - 1) / k; // ceil(x / k)
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (hoursNeeded(piles, mid) <= h) {
                ans = mid;        // valid → try smaller
                r = mid - 1;
            } else {
                l = mid + 1;      // too slow → increase speed
            }
        }

        return ans;
    }
};