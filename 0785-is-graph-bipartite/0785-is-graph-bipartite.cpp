class Solution {
public:
    bool DFS(vector<vector<int>> adj, vector<int> &colors, int node, int node_color) {
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

    bool BFS(vector<vector<int>> adj, vector<int> &colors, int node, int node_color) {
        queue<int> q;
        q.push(node);
        colors[node] = node_color;

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            for(int x: adj[front]) {

                if(colors[x] == colors[front]) return false;

                if(colors[x] == -1) {
                    q.push(x);
                    colors[x] = 1 - colors[front];
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // unordered_map<int, vector<int>> adj;
        // for(int i = 0; i < graph.size(); i++) {
        //     for(int x: graph[i]) {
        //         adj[i].push_back(x);
        //     }
        // }

        // no need to create an unordred map its already in the adjecency list form.

        //DFS approach

        // vector<int> colors(graph.size(), -1);
        // for(int i = 0; i < graph.size(); i++) {
        //     if(colors[i] == -1) {
        //         if(!DFS(graph, colors, i, 0)) return false;
        //     }
        // }
        // return true;

        //BFS approach
        vector<int> colors(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(colors[i] == -1) {
                if(!BFS(graph, colors, i, 0)) return false;
            }
        }
        return true; 
    }
};