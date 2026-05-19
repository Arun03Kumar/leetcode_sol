class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = INT_MIN;
        string st;
        for(char ch: s) {
            if(ch == '(') {
                st.push_back('(');
                count++;
                ans = max(ans, count);
            }
            else if(ch == ')') {
                count--;
                st.pop_back();
            }
        }
        return max(ans, count);
    }
};