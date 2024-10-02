class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Approach 1: Simulation

        int n = tickets.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            q.push({i, tickets[i]});
        }

        int ans = 0;
        while(!q.empty()) {
            int idx = q.front().first;
            int rem_ticks = q.front().second;
            q.pop();
            ans++;

            if(rem_ticks - 1 != 0) {
                q.push({idx, rem_ticks - 1});
            }
            else if(idx == k) {
                break;
            }

        }

        return ans;
    }
};