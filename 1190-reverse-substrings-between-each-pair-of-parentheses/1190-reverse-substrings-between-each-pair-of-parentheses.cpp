class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans = "";
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                count++;
            }
            else if(s[i] == ')') {
                count++;
                string tmp_ans = "";
                while(st.top() != '(') {
                    tmp_ans += st.top();
                    st.pop();
                }
                st.pop();
                for(char x: tmp_ans) {
                    st.push(x);
                }
                // if(i == s.size() - 1) ans = tmp_ans;
            }
            else {
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
                ans += st.top();
                st.pop();
            }
        reverse(ans.begin(), ans.end());
        // if(ans.size() == 0) {
        //     while(!st.empty()) {
        //         ans += st.top();
        //         st.pop();
        //     }
        //     reverse(ans.begin(), ans.end());
        // }
        // if(ans.size() != s.size() - count) {
        //     while(!st.empty()) {
        //         cout << st.top();
        //         st.pop();
        //     }
        // }
        // cout << ans;
        return ans;
    }
};