class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // int n = arrival.size();

        // // free[i][0] = time when server i becomes free
        // // free[i][1] = number of requests handled by server i
        // vector<vector<int>> free(k, vector<int>(2, 0));

        // int ans = 0;

        // for(int i = 0; i < n; i++) {
        //     int time = arrival[i];

        //     int server = i % k;
        //     int cnt = 0;

        //     // Find the next available server
        //     while(cnt < k && time < free[server][0]) {
        //         server = (server + 1) % k;
        //         cnt++;
        //     }

        //     // All servers are busy
        //     if(cnt == k) continue;

        //     // Assign request to the available server
        //     free[server][0] = time + load[i];
        //     free[server][1]++;

        //     ans = max(ans, free[server][1]);
        // }

        // vector<int> b;

        // // Find all busiest servers
        // for(int i = 0; i < k; i++) {
        //     if(free[i][1] == ans) {
        //         b.push_back(i);
        //     }
        // }

        // return b;


        // the whole process above can be faster using sets to store the free servers and min heap to store the busy servers

        set<int> free;
        for(int i = 0; i < k; i++) {
            free.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];

            while(!busy.empty() && time >= busy.top().first) {
                int server = busy.top().second;
                free.insert(server);
                busy.pop();
            }

            if(free.empty()) continue;

            int target = i % k;

            auto it = free.lower_bound(target);

            if(it == free.end()) {
                it = free.begin();
            }

            int server = *it;

            free.erase(server);
            count[server]++;

            busy.push({time + load[i], server});
        }

        int max_b = *max_element(begin(count), end(count));

        vector<int> ans;

        for(int i = 0; i < count.size(); i++) {
            if(count[i] == max_b) ans.push_back(i);
        }

        return ans;
    }
};