class Solution {
public:
    void dfs(vector<int>& edges, vector<int> &dist_arr, int node, vector<int> &visited) {
        visited[node] = 1;

        if(edges[node] == -1) return;

        int v = edges[node];
        if(!visited[v]) {
            visited[v] = 1;
            dist_arr[v] = dist_arr[node] + 1;
            dfs(edges, dist_arr, v, visited);
        }


    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // fill the two distance array for both the nodes with bfs or dfs
        // these distance array will give the distance for each node from the given node1 and node2, distance for node1 and node2 is 0, nodes which can not be reached from the node1, node2 are marked inf.
        // iterate over these dist array find which node is at max distance and if that max distance is lesser than previous min dis, update it and also update the ans.

        int n = edges.size();
        vector<int> distance_from_node1(n, INT_MAX);
        vector<int> distance_from_node2(n, INT_MAX);

        vector<int> visited1(n, 0), visited2(n, 0);

        distance_from_node1[node1] = 0;
        distance_from_node2[node2] = 0;

        dfs(edges, distance_from_node1, node1, visited1);
        dfs(edges, distance_from_node2, node2, visited2);

        int ans = -1;
        int min_dist_curr = INT_MAX;

        for(int i = 0; i < n; i++) {
            int max_dist = max(distance_from_node1[i], distance_from_node2[i]);

            if(max_dist < min_dist_curr) {
                min_dist_curr = max_dist;
                ans = i;
            }
        }

        return ans;
    }
};