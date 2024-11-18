class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        int n = s.size() - 1;
        string ans = "", temp;
        while(n >= 0) {
            if(s[n] != ' ') {
                st.push(s[n]);
            }
            else {
                temp = "";
                while(!st.empty()) {
                    temp += st.top();
                    st.pop();
                }
                if(!temp.empty()) ans += temp + ' ';
            }
            n--;
        }
        temp = "";
        while(!st.empty()) {
                    temp += st.top();
                    st.pop();
                }
                if(!temp.empty()) ans += temp;

        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};