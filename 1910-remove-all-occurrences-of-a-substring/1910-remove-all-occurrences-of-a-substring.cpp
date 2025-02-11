class Solution {
public:
    bool check(stack<int> &st, string &part, int &n) {
        stack<int> temp = st;

        for(int i = n - 1; i >= 0; i--) {
            if(temp.top() != part[i]) {
                return false;
            }

            temp.pop();
        }

        return true;
    }

    string removeOccurrences(string s, string part) {
        // Approach 1: Bruteforce
        // while(true) {
        //     int idx = s.find(part);
        //     if(idx == string::npos) break;
        //     s.erase(idx, part.size());
        // }

        // return s;


        // Approach 2: Stack
        int m = s.size();
        int n = part.size();

        stack<int> st;

        for(int i = 0; i < m; i++) {
            st.push(s[i]);

            if(st.size() >= n && check(st, part, n) == true) {
                for(int j = 0; j < n; j++) {
                    st.pop();
                }
            }
        }

        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};