class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            if(st.find(A[i]) != st.end()) cnt++;
            if(st.find(B[i]) != st.end()) cnt++;
            if(A[i] == B[i]) cnt++;
            st.insert(A[i]);
            st.insert(B[i]);
            if(!ans.empty())
                ans.push_back(ans.back() + cnt);
            else ans.push_back(cnt);
        }

        return ans;
    }
};