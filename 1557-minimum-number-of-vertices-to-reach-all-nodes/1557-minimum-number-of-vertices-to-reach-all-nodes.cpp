class Solution {
public:
    void bfs(unordered_map<int, vector<int>> &adj, int node, vector<int> &visited, vector<int> &indegree) {
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
                    indegree[x]--;
                }
            }

        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> visited(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && indegree[i] == 0) {
                bfs(adj, i, visited, indegree);
                ans.push_back(i);
            }
        }

        return ans;
    }
};