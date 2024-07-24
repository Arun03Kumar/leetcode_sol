class Solution {
public:
    void bfs(unordered_map<int, vector<int>> &adj, int node, vector<int> &visited) {
        queue<int> q;
        visited[node] = 1;
        q.push(node);

        while(!q.empty()) {

            int front = q.front();
            q.pop();

            for(auto x: adj[front]) {
                if(!visited[x]) {
                    visited[x] = 1;
                    q.push(x);
                }
            }

        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> visited(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bfs(adj, i, visited);
                ans.push_back(i);
            }
        }

        return ans;
    }
};