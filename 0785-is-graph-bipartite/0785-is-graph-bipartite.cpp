class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> &adj, int node, int val, vector<int> &color) {
        if(color[node] != -1) return true;

        color[node] = val;

        for(int &nbr: adj[node]) {
            if(color[nbr] == val) return false;
            bool x = DFS(adj, nbr, 1 - val, color);
            if(!x) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < graph.size(); i++) {
            adj[i] = graph[i];
        }

        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                bool x = DFS(adj, i, 0, color);
                if(!x) return false;
            }
        }
        return true;
    }
};