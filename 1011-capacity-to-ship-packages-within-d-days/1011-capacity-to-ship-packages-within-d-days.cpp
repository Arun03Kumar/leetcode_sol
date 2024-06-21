class Solution {
public:
    bool can_ship(vector<int> w, int d, int m) {
        int curr_size = m, days = 1;
        for(int x: w) {
            if(curr_size - x < 0) {
                days += 1;
                curr_size = m;
            }
            curr_size -= x;
        }
        return days <= d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // if ship capacity is smaller than any of the packages weight then it won't be possible to ship so minimum value should be the maximum weight of the package and the maximum capacity of the ship should be sumof all the packages weight, now we got the upper and lower range in which we can do binary search, and for each mid value we can see if it is possible to ship all in the given days, if it possible then we can check if any other value which is smaller is present.
        int sum = 0, max_elem = -1;
        for(int x: weights) {
            sum += x;
            max_elem = max(x, max_elem);
        }
        int low = max_elem, high = sum, ans = sum;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(can_ship(weights, days, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};