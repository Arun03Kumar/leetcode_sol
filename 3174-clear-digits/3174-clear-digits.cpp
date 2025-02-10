class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        
        for(char ch: s) {
            if(ch >= 'a' && ch <= 'z') {
                st.push(ch);
            }
            else {
                if(!st.empty()) st.pop();
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};