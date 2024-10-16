class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) st.push(asteroids[i]);
            else {
                while(!st.empty() && st.top() <= abs(asteroids[i])) {
                    st.pop();
                }
            }
        }

        int size = st.size();
        vector<int> ans(size);
        while(!st.empty()) {
            ans[--size] = st.top();
            st.pop();
        }

        return ans;
    }
};