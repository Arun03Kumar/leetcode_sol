class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int count = 0;

        for(char ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if(!st.empty() && ch == ')' && st.top() == '(') st.pop();
                else if(!st.empty() && ch == ']' && st.top() == '[') st.pop();
                else if(!st.empty() && ch == '}' && st.top() == '{') st.pop();
                else count++;
            }
        }

        return st.empty() && count == 0;
    }
};