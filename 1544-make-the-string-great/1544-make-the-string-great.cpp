class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(char ch: s) {
            if(!st.empty()) {
                char top = st.top();
                if(top - 32 == ch || top + 32 == ch) st.pop();
                else st.push(ch);
            }
            else st.push(ch);
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};