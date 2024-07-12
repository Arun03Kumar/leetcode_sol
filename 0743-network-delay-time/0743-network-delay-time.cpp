class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto x: times) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v, wt});
        }

        set<pair<int, int>> st;
        vector<int> distance(n + 1, INT_MAX);
        // vector<int> parent(n + 1);
        // for(int i = 0; i <= n; i++) parent[i] = i;

        distance[k] = 0;
        st.insert({0, k});

        while(!st.empty()) {
            auto &it = *st.begin();
            int d = it.first;
            int node = it.second;
            st.erase(it);

            for(auto x: adj[node]) {
                int neighbour = x.first;
                int wt = x.second;

                if(d + wt < distance[neighbour]) {

                    if(distance[neighbour] != INT_MAX) {
                        st.erase({distance[neighbour], neighbour});
                    }

                    distance[neighbour] = d + wt;
                    st.insert({d + wt, neighbour});
                    // parent[neighbour] = node;
                }
            }
        }

        int ans = INT_MIN;

        for(int i = 1; i <= n; i++) {
            ans = max(ans, distance[i]);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};