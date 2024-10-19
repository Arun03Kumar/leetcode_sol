class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // in the stack we will store those elements which are greater than the current element
        // if top of stack is smaller than current index valuw then we will keep on popping until we get the larger element on the top
        // and when we get the larger element on the top then we push the current element in the stack
        // instead of storing the element we could store the indexes, because in the answer we just need the count of days

        stack<int> st;
        int n = temperatures.size();

        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {

            int curr_el = temperatures[i];
            while(!st.empty() && temperatures[st.top()] <= curr_el) st.pop();
            
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }

        return ans;
    }
};