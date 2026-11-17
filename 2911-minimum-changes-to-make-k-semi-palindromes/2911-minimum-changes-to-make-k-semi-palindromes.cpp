class Solution {
public:
    vector<vector<int>> cost_dp;
    vector<vector<int>> rec_dp;

    int cost(int l, int r, string &s) {

        if(cost_dp[l][r] != -1) return cost_dp[l][r];

        int len = r - l + 1;

        int min_cost = INT_MAX;
        for(int d = 1; d < len; d++) {
            if(len % d != 0) continue;

            int c = 0;
            for(int i = 0; i < d; i++) {
                int left = l + i;
                int right = left + (len / d - 1) * d;

                while(left < right) {
                    if(s[left] != s[right]) c++;
                    left += d;
                    right -= d;
                } 
            }

            min_cost = min(min_cost, c);
        }

        return cost_dp[l][r] = min_cost;
    }

    int recursion(string &s, int k, int idx) {
        if(k == 0) {
            if(idx == s.size()) return 0;
            return INT_MAX;
        }

        // string curr = "";
        int temp = INT_MAX;
        for(int i = idx + 1; i < s.size(); i++) {
            // curr.push_back(s[i]);
            // if(curr.size() == 1) continue;
            int c = cost(idx, i, s);
            int p = recursion(s, k - 1, i + 1);
            if(p == INT_MAX) continue;
            temp = min(temp, c + p);
        }
        
        return temp;
    }

    int dp(string &s, int k, int idx) {
        if(k == 0) {
            if(idx == s.size()) return 0;
            return INT_MAX;
        }

        // string curr = "";
        if(rec_dp[k][idx] != -1) return rec_dp[k][idx];

        int temp = INT_MAX;
        for(int i = idx + 1; i < s.size(); i++) {
            // curr.push_back(s[i]);
            // if(curr.size() == 1) continue;
            int c = cost(idx, i, s);
            int p = dp(s, k - 1, i + 1);
            if(p == INT_MAX) continue;
            temp = min(temp, c + p);
        }
        
        return rec_dp[k][idx] = temp;
    }

    int minimumChanges(string s, int k) {
        // unordered_map<string, int> mp;
        int n = s.size();
        cost_dp.assign(n + 1, vector<int>(n + 1, -1));
        rec_dp.assign(n + 1, vector<int>(n + 1, -1));
        // return recursion(s, k, 0);
        return dp(s, k, 0);
        // dp(s, k, 0, mp);
        // return ans;
    }
};