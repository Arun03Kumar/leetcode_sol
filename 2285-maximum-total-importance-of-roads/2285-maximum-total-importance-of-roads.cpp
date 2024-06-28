class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //just assign largest number to the node with maximum degree
        // we can compute answer direcly by assigning the number multiplied by degree.
        vector<int> degree(n, 0);
        for(auto x: roads) {
            int u = x[0], v = x[1];
            degree[u]++;
            degree[v]++;
        }

        long long ans = 0;
        sort(degree.begin(), degree.end());
        // sorted the degree so that we can assign the numbers easily, multiplying smallest degree with smallest number and largest degree with largest number.
        for(int i = 0; i < n; i++) {
            ans += degree[i] * 1LL * (i + 1) * 1LL;
        }
        return ans;
    }
};