class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;

        unordered_map<int, int> indegree, outdegree;

        for(auto &x: pairs) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        int start_node = pairs[0][0];
        for(auto &x: adj) {
            int node = x.first;
            if(outdegree[node] - indegree[node] == 1) {
                start_node = node;
                break;
            }
        }

        vector<int> euler_path;
        stack<int> st;
        st.push(start_node);

        while(!st.empty()) {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            }
            else {
                euler_path.push_back(curr);
                st.pop();
            }
        }

        reverse(begin(euler_path), end(euler_path));
        vector<vector<int>> ans;

        for(int i = 0; i < euler_path.size() - 1; i++) {
            ans.push_back({euler_path[i], euler_path[i + 1]});
        }

        return ans;
    }
};