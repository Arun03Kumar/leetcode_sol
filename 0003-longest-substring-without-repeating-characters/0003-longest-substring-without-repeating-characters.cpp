class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> check;
        int l = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            while(check.find(s[i]) != check.end()) {
                check.erase(s[l]);
                l++;
            }
            check.insert(s[i]);
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};