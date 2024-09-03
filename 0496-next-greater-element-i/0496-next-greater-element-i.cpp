class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums1[i]] = i;
        }

        stack<int> st;

        for(int i = 0; i < m; i++) {

            while(!st.empty() && st.top() < nums2[i]) {
                int top = st.top();
                if(mp.find(top) != mp.end()) {
                    ans[mp[top]] = nums2[i];
                }
                st.pop();
            }

            st.push(nums2[i]);

        }

        return ans;
    }
};