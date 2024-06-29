class Solution {
public:
    void DFS(int node, unordered_map<int, vector<int> > adj, vector<bool> &visited) {
        visited[node] = true;
        for(int v: adj[node]) {
            if(visited[v] == false) {
                DFS(v, adj, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // 1. reverse the direction of edges and traverse for every node so which node it will visit that would be its parent.
        // 2. do the topological sorting and the traverse in topological order so in this way when we find any parent of any node then we can use also say that parent of that node will also be the parent.

        //Approach 1.
        // unordered_map<int, vector<int> > adj;
        // vector<vector<int> > ans;
        // for(int i = 0; i < edges.size(); i++) {
        //     int u = edges[i][0];
        //     int v = edges[i][1];

        //     adj[v].push_back(u);
        // } 

        // for(int u = 0; u < n; u++) {
        //     vector<bool> visited(n, false);
        //     DFS(u, adj, visited);
            
        //     vector<int> ancestors;
        //     for(int i = 0; i < n; i++) {
        //         if(i == u) continue;
        //         if(visited[i]) { // i != u because we dont want to add same node in the answer
        //             ancestors.push_back(i);
        //         }
        //     }
        //     ans.push_back(ancestors);
        // }
        // return ans;


        // Approach 2.

        unordered_map<int, vector<int> > adj;
        vector<int> indegree(n, 0);

        for(auto x: edges) {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> que;
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> topological_order;
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            topological_order.push_back(curr);
            for(int x: adj[curr]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    que.push(x);
                }
            }
        }

        vector<unordered_set<int> > parent_of_idx_i_in_toposort(n);
        for(int node: topological_order) {
            for(int x: adj[node]) {
                parent_of_idx_i_in_toposort[x].insert(node);
                parent_of_idx_i_in_toposort[x].insert(parent_of_idx_i_in_toposort[node].begin(), parent_of_idx_i_in_toposort[node].end());
            }
        }

        vector<vector<int> > ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = vector<int>(parent_of_idx_i_in_toposort[i].begin(), parent_of_idx_i_in_toposort[i].end());
            sort(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};