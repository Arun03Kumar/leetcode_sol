class Solution {
public:
    string makeGood(string s) {
        // stack<char> st;

        // for(char ch: s) {
        //     if(!st.empty()) {
        //         char top = st.top();
        //         if(top - 32 == ch || top + 32 == ch) st.pop();
        //         else st.push(ch);
        //     }
        //     else st.push(ch);
        // }

        // string ans = "";
        // while(!st.empty()) {
        //     ans += st.top();
        //     st.pop();
        // }

        // reverse(begin(ans), end(ans));
        // return ans;

        // Approach 2:
        string ans = "";

        for(char ch: s) {
            if(ans.size() == 0) ans.push_back(ch);
            else {
                char back = ans.back();
                if(back - 32 == ch || back + 32 == ch) {
                    ans.pop_back();
                }
                else {
                    ans.push_back(ch);
                }
            }
        }

        return ans;
    }
};