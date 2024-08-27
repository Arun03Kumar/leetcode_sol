class Solution {
public:
    typedef pair<double, int> P;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // its just a variation of dijkstra's
        // we need to find the distance from start to end node but in opposite way becuase here we want to find maximum
        // distance array stores the probability from start to that node
        // distance of start from start will be 1 becuse for going from same node to same node probability will be 1.
        
        unordered_map<int, vector<pair<int, double>>> adj;
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<P, vector<P>> pq;
        pq.push({1.0, start_node});

        vector<double> distance(n, 0);
        distance[start_node] = 1.0;

        while(!pq.empty()) {

            double curr_prob = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();

            for(auto &nbr: adj[curr_node]) {

                int nbr_node = nbr.first;
                double wt = nbr.second;

                if(curr_prob * wt > distance[nbr_node]) {

                    distance[nbr_node] = curr_prob * wt;
                    pq.push({distance[nbr_node], nbr_node});

                }
            }
        }

        return distance[end_node];
    }
};