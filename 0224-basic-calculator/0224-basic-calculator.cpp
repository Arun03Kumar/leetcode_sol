class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        int ans = 0;
        int sign = 1;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if(ch == '+' || ch == '-') {
                ans += num * sign;
                num = 0;
                sign = (ch == '-') ? -1 : 1;
            }
            else if(ch == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            else if(ch == ')') {
                ans += num * sign;
                num = 0;

                int prev_sign = st.top();
                st.pop();
                int prev_ans = st.top();
                st.pop();

                ans = prev_ans + prev_sign * ans;
            }
        }

        ans += num * sign;
        return ans;
    }
};