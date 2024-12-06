class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(begin(banned), end(banned));

        int ans = 0;
        for(int i = 1; i <= min(n, maxSum); i++) {
            if(st.find(i) != st.end()) continue;

            if(i <= maxSum) {
                ans++;
                maxSum -= i;
            }
        }

        return ans;
    }
};