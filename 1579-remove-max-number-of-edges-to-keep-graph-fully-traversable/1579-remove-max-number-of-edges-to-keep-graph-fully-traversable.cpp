class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        int components;

        DSU(int x) {
            parent.resize(x + 1);
            rank.resize(x + 1);
            components = x;
            for(int i = 1; i <= x; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if(x == parent[x])
                return x;
            
            return parent[x] = find(parent[x]);
        }

        void Union(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if(x_parent == y_parent) return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            }
            else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }

            components--;
        }

        bool is_single_component() {
            return components == 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n), Bob(n);

        auto lambda = [](vector<int> v1, vector<int> v2) {
            return v1[0] > v2[0];
        };
        sort(edges.begin(), edges.end(), lambda);

        int edge_count = 0;
        for(auto edge: edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3) {
                bool if_edge_added_or_not = false;
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    if_edge_added_or_not = true;
                }

                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    if_edge_added_or_not = true;
                }

                if(if_edge_added_or_not)
                    edge_count++;
            }
            else if(type == 2) {
                if(Bob.find(u) != Bob.find(v)) {
                    Bob.Union(u, v);
                    edge_count++;
                }
            }
            else {
                if(Alice.find(u) != Alice.find(v)) {
                    Alice.Union(u, v);
                    edge_count++;
                }
            }
        }
        if(Alice.is_single_component() && Bob.is_single_component()) {
            return edges.size() - edge_count;
        }
        return -1;
    }
};