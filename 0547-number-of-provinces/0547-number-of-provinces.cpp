class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<int> &visited, int v, int node) {
        visited[node] = true;
        for(int i = 0; i < v; i++) {
            if(!visited[i] && isConnected[node][i]) {
                DFS(isConnected, visited, v, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited(v, 0);
        int ans = 0;
        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                DFS(isConnected, visited, v, i);
                ans++;
            }
        }
        return ans;
    }
};