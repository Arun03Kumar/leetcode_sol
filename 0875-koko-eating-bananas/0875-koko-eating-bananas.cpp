class Solution {
public:
    long long time_taken(vector<int> &p, int mid) {
        long long ans = 0;
        for(int x: p) {
            int temp = x / mid;
            ans += (x % mid == 0 ? temp : temp + 1);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_num = INT_MIN;
        for(int x: piles) max_num = max(x, max_num);

        int l = 1, r = max_num;
        int ans = max_num;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            // cout << mid << endl;

            long long val = time_taken(piles, mid);
            // cout << val << " ";
            if(val <= h) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};