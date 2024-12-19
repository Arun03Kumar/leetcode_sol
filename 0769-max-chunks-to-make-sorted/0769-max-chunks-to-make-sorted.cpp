class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix_i(n), suffix_after_i(n);
        prefix_i[0] = arr[0];
        suffix_after_i[n - 1] = arr[n - 1];

        for(int i = 1; i < n; i++) {
            prefix_i[i] = max(prefix_i[i - 1], arr[i]);
        }

        for(int i = n - 2; i >= 0; i--) {
            suffix_after_i[i] = min(arr[i], suffix_after_i[i + 1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int max_before_i = i > 0 ? prefix_i[i - 1] : -1;
            int min_after_i = suffix_after_i[i];
            if(max_before_i < min_after_i) {
                ans++;
            }
        }

        return ans;
    }
};