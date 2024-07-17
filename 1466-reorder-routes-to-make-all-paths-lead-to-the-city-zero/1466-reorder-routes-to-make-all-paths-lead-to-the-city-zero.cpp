class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int, bool>>> &adj, vector<int> &visited, int from, int &ans) {
        visited[from] = 1;

        for(auto to: adj[from]) {
            int v = to.first;
            bool is_real = to.second;

            if(visited[v] == 0) {
                if(is_real) { // from parent to child we can go with real edge it means we can not go to parent from the child hence we have to change the direction
                    ans++;
                }
                dfs(adj, visited, v, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // since it is given that only one way is present so we can create a adjecency list which is bidirectional, but we need to also store if it is already present in real graph, if not then we need to mark it.
        // the main crux is if we start from 0 then we check if we can go to its neighbour, and if we can go to its neighbour with the help of real edge then it means we have to flip it and increase the answer, 
        // from 0 to 1 one edge is present we can go to 1 with that edge it means from 1 we can not go to 0 hence we have to flip it.
        unordered_map<int, vector<pair<int, bool>>> adj;

        vector<int> visited(n, 0);
        int ans = 0;

        for(auto x: connections) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back({v, true});
            adj[v].push_back({u, false});
        }

        dfs(adj, visited, 0, ans);
        
        return ans;
    }
};