class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &visited, string start, string end, double &ans, double temp) {
        if(start == end) {
            ans = temp;
            return;
        }
        visited.insert(start);

        for(auto x: adj[start]) {
            if(visited.find(x.first) == visited.end()){
                // temp = temp * x.second;
                cout << ans << " ";
                dfs(adj, visited, x.first, end, ans, temp * x.second);
            }
        }

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // its hard to came up that its a graph problem but visualize it that way that you have to traevrse over map, if you are storing it into map, and we know that this is done in bfs/dfs.

        // one key thing is that when we create graph also add that from v to u it will take 1 / val.

        // we have to pass both the ans and temp variable into the dfs. 

        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> ans;

        for(auto q: queries) {
            string start = q[0];
            string end = q[1];

            if(adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double temp = -1.0;
            dfs(adj, visited, start, end, temp, 1.0);
            ans.push_back(temp);
        }

        return ans;
    }
};