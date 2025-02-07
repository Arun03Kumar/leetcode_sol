class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        unordered_map<int, int> freq_col, mp;
        unordered_set<int> st;
        vector<int> ans;

        for(vector<int> q: queries) {
            int el = q[0];
            int col = q[1];

            if(mp.find(el) == mp.end()) {
                st.insert(col);
                mp[el] = col;
                freq_col[col]++;
            }
            else {
                int prev = mp[el];
                freq_col[prev]--;

                if(freq_col[prev] == 0) {
                    st.erase(prev);
                }

                st.insert(col);
                mp[el] = col;
                freq_col[col]++;

            }

            ans.push_back(st.size());
        }

        return ans;
    }
};