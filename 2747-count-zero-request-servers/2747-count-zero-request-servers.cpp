class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // int mx = 0;
        // for(vector<int> x: logs) {
        //     mx = max(mx, x[1]);
        // }

        // for(int q : queries) {
        //     mx = max(mx, q);
        // }
        // // vector<int> ans(mx + 1, 0);
        // vector<unordered_set<int>> ans(mx + 1);

        // for(vector<int> x: logs) {
        //     int id = x[0];
        //     int time = x[1];
        //     ans[time].insert(id);
        // }

        // // vector<int> prefix;
        // // prefix.push_back(0);
        // // prefix.push_back(ans[1]);

        // // for(int i = 2; i < ans.size(); i++) {
        // //     prefix.push_back(prefix.back() + ans[i]);
        // // }

        // vector<int> cnt;
        // for(int q: queries) {
        //     // int e = q;
        //     // int s = (q - x > 0) ? q - x: 0;

        //     unordered_set<int> active;

        //     for(int t = max(0, q - x); t <= q; t++) {
        //         for(int id : ans[t]) {
        //             active.insert(id);
        //         }
        //     }

        //     cnt.push_back(n - active.size());

        //     // cnt.push_back(prefix[e] - prefix[s]);
        // }

        // return cnt;


        auto lambda = [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        };
        sort(begin(logs), end(logs), lambda);

        vector<vector<int>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(begin(q), end(q));

        int i = 0, j = 0;
        unordered_map<int, int> freq;
        vector<int> ans(q.size());

        int active = 0;

        for(auto t: q) {
            int time = t[0];
            int idx = t[1];
            while(j < logs.size() && logs[j][1] <= time) {
                int id = logs[j][0];
                if(freq[id] == 0) {
                    active++;
                }

                freq[id]++;
                j++;
            }

            while(i < j && logs[i][1] < time - x) {
                int id = logs[i][0];
                freq[id]--;
                if(freq[id] == 0) {
                    active--;
                }
                i++;
            }

            ans[idx] = n - active;
        }
        return ans;
    }
};