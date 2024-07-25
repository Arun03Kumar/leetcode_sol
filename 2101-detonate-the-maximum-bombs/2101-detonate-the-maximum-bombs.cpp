class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int node, int &tmp, vector<int> &visited) {
        visited[node] = 1;
        tmp++;

        for(int x: adj[node]) {
            if(!visited[x]) {
                dfs(adj, x, tmp, visited);
            }
        }

    }
    long long distance(vector<int> f, vector<int> s) {
        long long cal = (f[0] - s[0]) * 1LL * (f[0] - s[0]) * 1LL + (f[1] - s[1]) * 1LL * (f[1] - s[1]) * 1LL;
        // long long sqrt_cal = sqrt(cal);

        // cout << f[0] << " " << s[0] << cal << " " << sqrt_cal << endl;
        return cal;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        unordered_map<int, vector<int>> adj;

        int n = bombs.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                
                if(i != j) {
                    long long dist = distance(bombs[i], bombs[j]);
                    if(dist <= (bombs[i][2] * 1LL * bombs[i][2] * 1LL)) {
                        adj[i].push_back(j);
                    }
                }
            }
        }

        // for(auto x: adj) {
        //     cout << x.first << "->";
        //     for(int y: x.second) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            int temp_ans = 0;
            dfs(adj, i, temp_ans, visited);
            ans = max(ans, temp_ans);
        }

        return ans;
    }
};