class Solution {
public:
    typedef pair<int, int> P;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> wait;
        for(int i = 0; i < n; i++) {
            pq.push({servers[i], i});
        } 

        int idx = 0;
        int curr_time = 0;

        vector<int> ans(m);
        
        while(idx < m) {
            if (pq.empty() && !wait.empty()) {
                curr_time = wait.top()[0];
            }

            while(!wait.empty() && wait.top()[0] <= curr_time) {
                auto top = wait.top();
                pq.push({top[1], top[2]});
                wait.pop();
            }

            while (idx < m && curr_time >= idx && !pq.empty()) {
                auto top = pq.top();
                pq.pop();
                ans[idx] = top.second;

                wait.push({curr_time + tasks[idx], top.first, top.second});
                idx++;
            }

            curr_time++;

        }

        return ans;
    }
};