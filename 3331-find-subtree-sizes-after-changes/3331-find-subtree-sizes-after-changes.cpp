class Solution {
public:
    void dfs(vector<int> &par, vector<int> &last, vector<int> &ans, int idx, string &s, unordered_map<int, vector<int>> &adj) {
        int last_seen = s[idx] - 'a';
        int nearest_anc = last[last_seen];

        last[last_seen] = idx;

        for(int v: adj[idx]) {
            dfs(par, last, ans, v, s, adj);
        }

        last[last_seen] = nearest_anc;

        if(idx != 0) {
            if(nearest_anc != -1) {
                par[idx] = nearest_anc;
                ans[nearest_anc] += ans[idx];
            }
            else {
                int p = par[idx];
                ans[p] += ans[idx];
            }

        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 1; i < n; i++) {
            int par = parent[i];
            adj[par].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> ans(n, 1);

        dfs(parent, last, ans, 0, s, adj);
        return ans;
    }
};