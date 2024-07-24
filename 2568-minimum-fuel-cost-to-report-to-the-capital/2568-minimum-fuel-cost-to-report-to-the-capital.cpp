class Solution {
public:
    // long long dfs(unordered_map<int, vector<int>> adj, vector<int> &visited, int source, long long &ans, int seats) {

    //     visited[source] = 1;

    //     long long count = 1;
    //     for(auto x: adj[source]) {
    //         if(!visited[x]) {
    //             count += dfs(adj, visited, x, ans, seats);
    //         }
    //     }

    //     long long temp = (count + seats - 1) / seats; // calculating ceiling of (count / seats)

    //     if(source != 0) ans += temp;
    //     return count;

    // }

    // int dfs(unordered_map<int, vector<int>> adj, int node, int par, long long &ans, int seats, int people = 1) {
    //     for(auto x: adj[node]) {
    //         if(x == par) continue;
    //         people += dfs(adj, x, node, ans, seats);
    //     }

    //     if(node != 0) ans += (people + seats - 1) / seats;

    //     return people;
    // }

    long long fuel = 0;
    int seats;

    int dfs(int src, unordered_map<int, vector<int>>& adjlist, set<int>& visit)
    {
        if (visit.find(src) != visit.end())
            return 0;
        
        visit.insert(src);
        int subtree = 1;
        for (auto neigh: adjlist[src])
        {
            subtree += dfs(neigh, adjlist, visit);
        }

        if (src != 0)
        {
            fuel += subtree % seats == 0 ? subtree / seats : subtree / seats + 1;
        }

        return subtree;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // if we know the number of people at each node then we can get the fuel count needed to go to the just parent node.
        // we can find this by ceil(num_of_people / seats)
        // so we recursively do this for all nodes.

        // int n = roads.size() + 1;

        // unordered_map<int, vector<int>> adj;
        // for(auto x: roads) {
        //     int u = x[0];
        //     int v = x[1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }  

        // vector<int> visited(n, 0);
        // long long ans = 0;

        // // dfs(adj, visited, 0, ans, seats);
        // dfs(adj, 0, -1, ans, seats);

        // return ans;

        unordered_map<int, vector<int>> adjlist;
        for (auto road: roads)
        {
            adjlist[road[0]].push_back(road[1]);
            adjlist[road[1]].push_back(road[0]);
        }

        set<int> visit;
        this->seats = seats;

        dfs(0, adjlist, visit);

        return fuel;

    }
};