class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> remove_idx;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(!st.empty()) st.pop();
                else remove_idx.insert(i);
            }
        }

        while(!st.empty()) {
            remove_idx.insert(st.top());
            st.pop();
        }

        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(remove_idx.find(i) == remove_idx.end()) {
                ans += s[i];
            }
        }

        return ans;
    }
};