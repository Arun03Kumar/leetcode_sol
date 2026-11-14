class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<int> st;
        int ans = INT_MAX;

        for(int j = l; j <= n; j++) {
            st.insert(prefix[j - l]);

            if(j - r - 1 >= 0) {
                auto it = st.find(prefix[j - r - 1]);
                st.erase(it);
            }

            auto it = st.lower_bound(prefix[j]);

            if(it != st.begin()) {
                it--;
                ans = min(ans, prefix[j] - *it);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};