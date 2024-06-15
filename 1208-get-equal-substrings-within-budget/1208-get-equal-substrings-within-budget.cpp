class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0, curr_cost = 0, ans = 0;
        while(r < s.size()) {
            curr_cost += abs(s[r] - t[r]);
            while(curr_cost > maxCost) {
                curr_cost -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};