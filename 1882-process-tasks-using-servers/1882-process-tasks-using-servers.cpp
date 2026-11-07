class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<vector<int>,
            vector<vector<int>>,
            greater<vector<int>>> pq, wait;

        for(int i = 0; i < servers.size(); i++) {
            pq.push({0, servers[i], i});
        }

        int i = 0;
        long long o_time = 0;

        vector<int> ans(tasks.size());

        while(i < tasks.size()) {

            o_time = max(o_time, (long long)i);

            if(pq.empty() && !wait.empty()) {
                o_time = max(o_time, (long long)wait.top()[0]);
            }

            while(!wait.empty() && o_time >= wait.top()[0]) {

                pq.push({
                    0,
                    wait.top()[1],
                    wait.top()[2]
                });

                wait.pop();
            }

            if(!pq.empty()) {

                auto curr = pq.top();
                pq.pop();

                ans[i] = curr[2];

                wait.push({
                    (int)(o_time + tasks[i]),
                    curr[1],
                    curr[2]
                });

                i++;
            }
        }

        return ans;
    }
};