class Solution {
public:
    void recursion(string &s, int idx, unordered_set<string> &st) {
        if(idx >= s.size()) return;
        for(int i = idx, j = 1; i < s.size(); i++, j++) {
            string substr = s.substr(i, j);

            if(st.find(substr) == st.end()) {
                st.insert(substr);
                recursion(s, idx + 1, st);
                break;
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        recursion(s, 0, st);
        return st.size();
    }
};