class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, int>>> adj, vector<int> &visited, int node, int &ans) {
        visited[node] = 1;

        for(auto x: adj[node]) {
            int nbr = x.first;
            int d = x.second;
            ans = min(ans, d);

            if(!visited[nbr]) {
                dfs(adj, visited, nbr, ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // its just a simple bfs/dfs
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto road: roads) {
            int u = road[0];
            int v = road[1];
            int d = road[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> visited(n + 1, 0);
        int ans = INT_MAX;

        dfs(adj, visited, 1, ans);

        return ans;
    }
};