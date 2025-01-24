class Solution {
public:
    bool cycle_DFS(vector<vector<int>>& graph, int node, vector<bool> &visited, vector<bool> &is_same_recursion) {

        visited[node] = true;
        is_same_recursion[node] = true;

        for(auto x: graph[node]) {

            if(visited[x] == false) {

                if(cycle_DFS(graph, x, visited, is_same_recursion)) {
                    return true;
                }

            }
            else if(is_same_recursion[x] == true) {
                return true;
            }

        }

        is_same_recursion[node] = false;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Approach 1: using DFS to find cycle in the graph
        // basically those nodes which form cycles wont be safe nodes 
        // so we can find the cycle using bfs and dfs both
        // but in bfs first we have to reverse all the nodes.

        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> is_same_recursion(V, false);

        for(int i = 0; i < V; i++) {

            if(!visited[i]) {

                cycle_DFS(graph, i, visited, is_same_recursion);

            }

        }

        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(is_same_recursion[i] == false) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};