class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s: tokens) {
            if(s == "+") {
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                st.push(first + sec);
            }
            else if(s == "-") {
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                st.push(first - sec);
            }
            else if(s == "*") {
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                st.push(first * sec);
            }
            else if(s == "/") {
                int sec = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                st.push(first / sec);
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};