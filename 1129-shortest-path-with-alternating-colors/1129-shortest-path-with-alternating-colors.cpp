class Solution {
public:
    void bfs(unordered_map<int, vector<pair<int, int>>> &adj, vector<vector<int>> &visited, int source, vector<int> &distance) {

        queue<vector<int>> q;
        visited[source][0] = 1;
        visited[source][1] = 1;
        q.push({source, 0, -1});

        while(!q.empty()) {

            int q_size = q.size();

            while(q_size--) {

                auto front = q.front();
                q.pop();

                int s = front[0];
                int d = front[1];
                int c = front[2];

                for(auto x: adj[s]) {
                    
                    int nbr = x.first;
                    char nbr_color = x.second;

                    if(!visited[nbr][nbr_color] && nbr_color != c) {
                        visited[nbr][nbr_color] = 1;
                        q.push({nbr, d + 1, nbr_color});
                        if(distance[nbr] == -1)
                            distance[nbr] = d + 1;
                    }

                }

            }

        }

    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // we have to create a 2d visited array and mark for blue and red edges 
        // if red edge is goint from node mark it visited for red, if blue edge is going mark is visited for blue
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto x: redEdges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back({v, 0});
        }

        for(auto x: blueEdges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back({v, 1});
        }

        vector<vector<int>> visited(n, vector<int>(2, 0));

        vector<int> ans(n, -1);
        ans[0] = 0;

        for(int i = 0; i < n; i++) {

            bfs(adj, visited, 0, ans);

        }

        return ans;
    }
};