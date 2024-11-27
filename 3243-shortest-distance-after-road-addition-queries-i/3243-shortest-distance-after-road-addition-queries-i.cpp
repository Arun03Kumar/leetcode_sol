class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans;

        for(vector<int> &v: queries) {
            adj[v[0]].push_back(v[1]);
            
            queue<int> q;
            q.push(0);

            int level = 0;
            bool flag = false;

            vector<bool> visited(n, false);
            visited[0] = true;

            while(!q.empty()) {
                int size = q.size();

                while(size--) {
                    int front = q.front();
                    q.pop();

                    if(front == n - 1) {
                        ans.push_back(level);
                        flag = true;
                        break;
                    }

                    for(int &nbr: adj[front]) {
                        if(!visited[nbr]) {
                            q.push(nbr);
                            visited[nbr] = true;
                        }
                    }
                }
                if(flag) break;
                level++;
            }
        }

        return ans;
    }
};