class Solution {
public:
    bool check(unordered_map<int, vector<pair<int, int>>> &adj, int mid, int n) {
        queue<int> q;
        vector<int> visited(n, 0);

        q.push(0);
        visited[0] = 1;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            for(pair<int, int> &p: adj[front]) {
                if(p.second <= mid && !visited[p.first]) {
                    q.push(p.first);
                    visited[p.first] = 1;
                }
            }
        }

        for(int &x: visited) {
            if(x == 0) return false;
        }

        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // whenever you see the term minimize the maximum or maximize the minimum think of binary search on answer
        
        int max_wt = 0;
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[v].push_back({u, wt});
            max_wt = max(max_wt, wt);
        }

        int l = 1, r = max_wt;
        int ans = -1;

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(adj, mid, n)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};