class Solution {
public:
    int bfs(unordered_map<int, vector<int>> &adj, int node, int n) {
        queue<int> q;
        vector<int> visited(n, 0);

        if(n == 1) return  {0};

        visited[node] = 1;
        q.push(node);

        int level = 0;
        while(!q.empty()) {
            int size_q = q.size();
            while(size_q--) {
                int front = q.front();
                q.pop();

                for(auto x: adj[front]) {
                    if(!visited[x]) {
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
            level++;
            
        }

        return level;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // if we iterate over each node and find the height then compare then it will give TLE.

        // in every cases there will be maximum of 2 nodes which will have the minimum tree, and they will have max number of indegree.

        // so we will start removing those nodes which have indegree 1, and we will do it till there are two nodes remianing.

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        // vector<int> ans;
        // int last_min = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     int temp = bfs(adj, i, n);
        //     if(last_min > temp) {
        //         ans.clear();
        //         ans.push_back(i);
        //         last_min = temp;
        //     }
        //     else if(temp == last_min) {
        //         ans.push_back(i);
        //     }
        // }

        // return ans;

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }

        while(n > 2) {

            int q_size = q.size();
            n -= q_size;

            while(q_size--) {
                int front = q.front();
                q.pop();

                for(auto x: adj[front]) {
                    indegree[x]--;

                    if(indegree[x] == 1) {
                        q.push(x);
                    }
                }
            }

        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};