class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        // create a 2d matrix of size 26*26 which represents the shortest distance from all 26 letters to 26 letters
        //use flloyd warshall to fill the shortest

        vector<vector<long long>> adj(26, vector<long long>(26, INT_MAX));

        int n = original.size();
        for(int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            long long wt = (long long)cost[i];

            adj[u][v] = min(adj[u][v], wt);
        }

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        long long ans = 0;

        for(int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(source[i] == target[i]) continue;

            if(adj[u][v] == INT_MAX) return -1;

            ans += adj[u][v];

        }

        return ans;
    }
};