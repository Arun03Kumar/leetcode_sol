class Solution {
public:
    string makeFancyString(string s) {
        stack<pair<char, int>> st;

        for(int i = s.size() - 1; i >= 0; i--) {
            if(st.empty()) {
                st.push({s[i], 1});
            }
            else {
                if(st.top().first == s[i] && st.top().second == 2) continue;
                else if(st.top().first == s[i]) {
                    st.push({s[i], st.top().second + 1});
                }
                else {
                    st.push({s[i], 1});
                }
            }
            
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top().first;
            st.pop();
        }

        return ans;

    }
};