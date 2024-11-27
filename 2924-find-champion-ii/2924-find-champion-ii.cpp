class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }

        int count = 0, ans;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                ans = i;
                count++;
                if(count > 1) return -1;
            }
        }

        return ans;
    }
};