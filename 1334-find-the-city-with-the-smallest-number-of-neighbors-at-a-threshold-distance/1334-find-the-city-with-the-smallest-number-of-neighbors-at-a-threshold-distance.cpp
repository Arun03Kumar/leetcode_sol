class Solution {
public:
    typedef pair<int, int> P;
    int dijkstras(unordered_map<int, vector<pair<int, int>>> &adj, int threshold, int node, int n) {

        priority_queue<P, vector<P>, greater<P>> pq;
        // vector<int> visited(n, 0);
        vector<int> distance(n, INT_MAX);

        pq.push({0, node});
        // visited[node] = 1;

        int count = 0;
        cout << endl;

        while(!pq.empty()) {

            int d = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();
            cout << curr_node << " ";

            for(auto x: adj[curr_node]) {

                int nbr = x.first;
                int wt = x.second;

                if(d + wt < distance[nbr]) {

                    // if(d + wt < distance[nbr]) {
                        // cout << nbr << " ";
                        // count++;
                        distance[nbr] = d + wt;
                        // visited[nbr] = 1;
                        pq.push({d + wt, nbr});
                    // }

                }

            }

        }

        for(int i = 0; i < n; i++) {
            if (i != node && distance[i] <= threshold) {
                count++;
            }
        }


        return count;

    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int min_nodes = INT_MAX;
        int ans;
        for(int i = 0; i < n; i++) {
            int temp = dijkstras(adj, distanceThreshold, i, n);
            // cout << temp << " ";
            if(temp <= min_nodes) {
                ans = i;
                min_nodes = temp;
            }
            // cout << ans << endl;
        }

        return ans;
    }
};