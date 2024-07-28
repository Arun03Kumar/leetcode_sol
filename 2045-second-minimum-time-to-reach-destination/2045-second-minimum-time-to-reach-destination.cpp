class Solution {
public:
    // typedef pair<int, int> P;
    #define P pair<int, int>

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        // we maintain two distance arrays, one for shorted distance from root to node and another second shortest distance from root to node.

        //time_passed / change will give how many times color change happens, even for green odd for red, if it is red then we have to add the waiting time in it.

        unordered_map<int, vector<int>> adj;

        for(auto x: edges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> d1(n + 1, INT_MAX);
        vector<int> d2(n + 1, INT_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 1});
        d1[1] = 0;

        while(!pq.empty()) {

            auto [time_passed, node] = pq.top();
            pq.pop();

            if(node == n && d2[n] != INT_MAX) {
                return d2[node];
            }

            int div = time_passed / change;
            if(div % 2 == 1) {
                time_passed = change * (div + 1);
            }

            for(auto nbr: adj[node]) {
                
                if(time_passed + time < d1[nbr]) {
                    d2[nbr] = d1[nbr];
                    d1[nbr] = time_passed + time;
                    pq.push({time_passed + time, nbr});
                }
                else if(time_passed + time < d2[nbr] && d1[nbr] != time_passed + time) {
                    d2[nbr] = time_passed + time;
                    pq.push({time_passed + time, nbr});
                }

            }

        }

        return -1;
    }
};