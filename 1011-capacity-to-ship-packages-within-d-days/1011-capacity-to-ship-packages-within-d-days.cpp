class Solution {
public:
    int find_days(vector<int> &w, int mid) {
        int count = 0, ans = 1;
        for(int x: w) {
            if(count + x <= mid) {
                count += x;
            }
            else {
                ans++;
                count = x;
            }
        }
        return ans;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0);
        int ans = r;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            int val = find_days(weights, mid);

            if(val <= days) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};