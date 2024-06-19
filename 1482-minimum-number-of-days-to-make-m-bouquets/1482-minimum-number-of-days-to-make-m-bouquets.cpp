class Solution {
public:
    bool possible(vector<int> arr, int day, int m, int k) {
        int count = 0, no_of_bloom = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= day) {
                count++;
            }
            else {
                no_of_bloom += (count / k);
                count = 0;
            }
        }
        no_of_bloom += (count / k);;
        return no_of_bloom >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long mul = m * 1LL * k * 1LL;
        if(bloomDay.size() < mul) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int x: bloomDay) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        int low = mini, high = maxi;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};