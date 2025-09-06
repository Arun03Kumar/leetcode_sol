class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int node, vector<int> &visited, vector<int> &idx, vector<char> &vals, string &s) {
        if(visited[node]) return;

        visited[node] = 1;
        idx.push_back(node);
        vals.push_back(s[node]);

        for(int &nbr: adj[node]) {
            if(!visited[nbr]) {
                dfs(adj, nbr, visited, idx, vals, s);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge: pairs) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int n = s.size();
        vector<int> visited(n, 0);

        string ans = s;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> idx;
                vector<char> vals;
                dfs(adj, i, visited, idx, vals, s);

                sort(begin(idx), end(idx));
                sort(begin(vals), end(vals));

                for(int i = 0; i < idx.size(); i++) {
                    ans[idx[i]] = vals[i];
                }

                idx.clear();
                vals.clear();
            }
        }

        return ans;
    }
};