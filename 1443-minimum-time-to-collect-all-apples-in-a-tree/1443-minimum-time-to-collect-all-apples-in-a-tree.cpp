class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &adj, int node, vector<int> &visited, vector<bool>& has_apple, int par) {

        // visited[node] = 1;

        int ans = 0;
        for(int x: adj[node]) {
            if(x == par) continue;

            int temp = dfs(adj, x, visited, has_apple, node);

            if(temp > 0 || has_apple[x]) {
                ans += temp + 2;
            }
        }

        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // ask the child to give the parent amount of time it needed to collect the apple if the given time by child is greater than the 0 it means child has the apple and the edge connecting to the child will also be counted in the array.
        // its a tree like structure (not necessary to be the binary tree) so dont need to use visited array we can just use parent variable to avoid the cycle of going back to the parent.
        
        unordered_map<int, vector<int>> adj;
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        // int ans = 0;
        return dfs(adj, 0, visited, hasApple, -1);
        // return ans;
    }
};