class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>> pq, wait;

        for(int i = 0; i < servers.size(); i++) {
            pq.push({0, servers[i], i});
        }

        int i = 0;
        long long o_time = 0;

        vector<int> ans(tasks.size());

        while(i < tasks.size()) {

            o_time = max(o_time, (long long)i);

            // If no server is available, jump to earliest free time
            if(pq.empty()) {
                o_time = wait.top()[0];
            }

            // Move all available servers back
            while(!wait.empty() && wait.top()[0] <= o_time) {

                auto curr = wait.top();
                wait.pop();

                pq.push({0, curr[1], curr[2]});
            }

            // Assign task
            auto curr = pq.top();
            pq.pop();

            ans[i] = curr[2];

            wait.push({
                o_time + tasks[i],
                curr[1],
                curr[2]
            });

            i++;
        }

        return ans;
    }
};