class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string ch: operations) {
            if(ch == "+") {
                int f = st.top();
                st.pop();
                int s = st.top();
                st.pop();

                st.push(s);
                st.push(f);
                st.push(s + f);
            }
            else if(ch == "D") {
                st.push(2 * st.top());
            }
            else if(ch == "C") st.pop();
            else {
                st.push(stoi(ch));
            }
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};