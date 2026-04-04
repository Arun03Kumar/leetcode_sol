class Solution {
public:
    int find_adj(vector<int> &arr, int mid, int k) {
        int count = 0;
    int ans = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] <= mid) {
            count++;
        } else {
            ans += count / k;
            count = 0;
        }
    }

    // leftover segment
    ans += count / k;

    return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0;
        int r = *max_element(begin(bloomDay), end(bloomDay));
        int ans = -1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            // cout << mid << " mid\n";

            int val = find_adj(bloomDay, mid, k);
            // cout << val << " val\n";
            if(val >= m) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};