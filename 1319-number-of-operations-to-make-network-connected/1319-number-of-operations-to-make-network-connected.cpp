class Solution {
public:
    // void DFS(unordered_map<int, vector<int>> adj, vector<int> &visited, int node) {
    //     visited[node] = 1;

    //     for(int x: adj[node]) {
    //         if(!visited[x]) {
    //             DFS(adj, visited, x);
    //         }
    //     }
    // }

    void BFS(unordered_map<int, vector<int>> adj, vector<int> &visited, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(int x: adj[front]) {
                if(!visited[x]) {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // DFS is giving memory limit exceeded
        if(connections.size() < n - 1) return -1;
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> visited(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                // DFS(adj, visited, i);
                BFS(adj, visited, i);
                ans++;
            }
        }
        cout << ans;
        return ans - 1;
    }
};