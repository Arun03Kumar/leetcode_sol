class Solution {
public:
    void dfs(unordered_map<int, vector<int>> adj, vector<int> &visited, stack<int> &st, int node, bool &cycle) {
        visited[node] = 1;

        for(auto x: adj[node]) {
            if(visited[x] == 0) {
                dfs(adj, visited, st, x, cycle);
            }
            else if(visited[x] == 1) {
                cycle = true;
                return;
            }
        }

        visited[node] = 2;
        st.push(node);
    }
    vector<int> toposort(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        for(auto x: edges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
        }

        vector<int> visited(n + 1, 0);
        stack<int> st;

        bool cycle = false;

        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0) {
                dfs(adj, visited, st, i, cycle);
                if(cycle) return {};
            }
        }

        vector<int> order;

        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        // form a topological sort on both given matrices, which gives which row should be first and which came after, similarly whihc col should be first or after.

        // if there is cycle then definitely no possible answer.

        // for cycle detection, we use visited array in which value 0 tells that node is not yet visited, 1 means currently visiting , 2 is visited.

        // so if we are at the node whcih is pointing to a node which is currently visiting then it means there is cycle.

        vector<int> topo_row = toposort(rowConditions, k);
        vector<int> topo_col = toposort(colConditions, k);

        if(topo_row.empty() || topo_col.empty()) return {};

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {

                if(topo_row[i] == topo_col[j]) {
                    ans[i][j] = topo_row[i];
                }
            }
        }

        return ans;
    }
};