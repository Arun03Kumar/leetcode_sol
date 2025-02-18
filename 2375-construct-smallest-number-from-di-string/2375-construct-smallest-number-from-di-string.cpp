class Solution {
public:
    string smallestNumber(string pattern) {
        // when we get I then we assign ans to the counter and counter everytime increasing, but when we get D we don't assign but increase the counter and when we get at the end we again pop and assign to ans
        int n = pattern.size();
        string ans = "";
        stack<char> st;
        int counter = 1;

        for(int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }

        return ans;
    }
};