class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> adj, vector<int> &colors, int node, int node_color) {
        colors[node] = node_color;
        for(int x: adj[node]) {
            if(colors[x] == node_color) {
                return false;
            }
            if(colors[x] == -1) {
                if(!DFS(adj, colors, x, 1 - node_color)) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < graph.size(); i++) {
            for(int x: graph[i]) {
                adj[i].push_back(x);
            }
        }

        vector<int> colors(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(colors[i] == -1) {
                if(!DFS(adj, colors, i, 0)) return false;
            }
        }
        return true;
    }
};