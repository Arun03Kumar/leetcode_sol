class Solution {
public:
    vector<int> toposort(unordered_map<int, vector<int>> adj, int V) {
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(int x: adj[i]) {
                indegree[x]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(!indegree[i]) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(int x: adj[front]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                    ans.push_back(x);
                }
            }
        }
        if(ans.size() != V) return {};
        else return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for(auto x: prerequisites) {
            int v = x[0];
            int u = x[1];
            adj[u].push_back(v);
        }
        return toposort(adj, numCourses);
    }
};