class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int l = 0, r = 0;
        int ans = 0;

        while(r < s.size()) {
            if(st.find(s[r]) == st.end()) {
                st.insert(s[r]);
                r++;
            }
            else {
                ans++;
                st.clear();
            }
        }

        return ans + 1;
    }
};