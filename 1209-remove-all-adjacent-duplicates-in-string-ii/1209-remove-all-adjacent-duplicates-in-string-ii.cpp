class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for(char ch: s) {
            if(!st.empty() && st.top().first == ch) {
                st.top().second += 1;

                if(st.top().second == k) st.pop();
            }
            else{
                st.push({ch, 1});
            }

        }

        string ans = "";
        while(!st.empty()) {
            int n = st.top().second;
            while(n--) ans += st.top().first;
            st.pop();
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};