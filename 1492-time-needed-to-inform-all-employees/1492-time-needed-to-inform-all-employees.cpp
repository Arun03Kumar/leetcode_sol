class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, vector<int>& informTime, int head, int curr_time, int &ans) {
        
        ans = max(ans, curr_time);

        for(int nbr: adj[head]) {
            DFS(adj, informTime, nbr, curr_time + informTime[head], ans);
        }

    }

    void BFS(unordered_map<int, vector<int>> &adj, vector<int>& informTime, int head, int &ans) {

        queue<pair<int, int>> q;
        q.push({head, 0});

        while(!q.empty()) {

            auto front = q.front();
            q.pop();
            int node = front.first;
            int time = front.second;

            ans = max(ans, time);
            
            for(int nbr: adj[node]) {
                q.push({nbr, time + informTime[node]});
            }

        }

    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++) {
            if(manager[i] == -1) continue;

            int v = i;
            int u = manager[i];

            adj[u].push_back(v);
        }

        int ans = 0;
        // DFS(adj, informTime, headID, 0, ans);
        BFS(adj, informTime, headID, ans);
        return ans;
    }
};