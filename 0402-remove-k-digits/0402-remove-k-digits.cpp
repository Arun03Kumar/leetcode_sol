class Solution {
public:
    string removeKdigits(string num, int k) {
        // a number is smaller when written in increasing order
        // so we have to write the number in increasing order and remove that digit which breaks this increasing order pattern
        // so use monotonic stack to do this
        // but it may possiblr that number is already in increasing order in that case remove k digits from the top of stack beacuse this will remove all the big digits and make the string smallest

        // stack<char> st;

        // for(char ch: num) {
        //     // int n = ch - '0';

        //     while(!st.empty() && st.top() > ch && k) {
        //         st.pop();
        //         k--;
        //     }

        //     // to remove trailing zeros like if 00200, it will remove starting zeros
        //     if(!st.empty() || ch != '0') {
        //         st.push(ch);
        //     }
        // }

        // // in case if we haven't removed all the k digits
        // while(!st.empty() && k--) {
        //     st.pop();
        // }

        // if(st.empty()) return "0";

        // string ans = "";
        // while(!st.empty()) {
        //     // this concatanation will give memory limit exceeded hence use string instead of stack
        //     ans = st.top() + ans;
        //     st.pop();
        // }

        // return ans;



        // Approach 2: using string as stack

        string ans = "";

        for(char ch: num) {
            while(ans.size() > 0 && ans.back() > ch && k) {
                ans.pop_back();
                k--;
            }

            if(ans.size() > 0 || ch != '0') {
                ans.push_back(ch);
            }
        }

        while(ans.size() > 0 && k--) {
            ans.pop_back();
        }

        if(ans.size() == 0) return "0";

        return ans;
    }
};