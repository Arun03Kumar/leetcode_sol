class Solution {
public:
    unordered_set<int> dfs(unordered_map<int, vector<int>> adj, int node, vector<int> &visited, unordered_map<int, unordered_set<int>> &indirect) {
        visited[node] = 1;
        
        unordered_set<int> temp;
        for(auto x: adj[node]) {
            if(!visited[x]) {
                unordered_set<int> returned = dfs(adj, x, visited, indirect);
                temp.insert(x);
                temp.insert(returned.begin(), returned.end());
            }
            else {
                // unordered_set<int> t;
                temp.insert(x);
                temp.insert(indirect[x].begin(), indirect[x].end());
                // return t;
            }
        }

        indirect[node].insert(temp.begin(), temp.end());
        return indirect[node];
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // go to recursively and return the dependency set of that node when dfs ends;
        
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<int> visited(numCourses, 0);

        unordered_map<int, unordered_set<int>> indirect;

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                dfs(adj, i, visited, indirect);
            }
        }

        // for(auto x: indirect) {
        //     cout << x.first << "->";
        //     for(auto y: x.second) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }

        vector<bool> ans;

        for(auto x: queries) {
            int v = x[1];
            int u = x[0];

            if(indirect[v].find(u) == indirect[v].end()) {
                ans.push_back(false);
            }
            else {
                ans.push_back(true);
            }
        }

        return ans;

    }
};