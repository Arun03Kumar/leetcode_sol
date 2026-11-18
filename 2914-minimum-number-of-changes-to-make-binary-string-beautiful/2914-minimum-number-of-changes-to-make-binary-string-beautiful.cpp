class Solution {
public:
    int rec(string &s, int idx, vector<int> &dp) {

        if(idx == s.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int temp = INT_MAX;
        int ones = 0, zeros = 0;
        // for(int i = idx + 2; i <= s.size(); i += 2) {
        //     int j = idx;
        //     int ones = 0, zeros = 0;
        //     while(j < s.size() && j < i) {
        //         if(s[j] == '1') {
        //             ones++;
        //         }
        //         else zeros++;
        //         j++;
        //     }
        //     int t = rec(s, i, dp);
        //     if(t != INT_MAX)
        //     temp = min(temp, min(ones, zeros) + t);
        // }
        for(int i = idx; i < s.size(); i++) {
            if(s[i] == '1') ones++;
            else zeros++;

            int len = i - idx + 1;
            if(len % 2 != 0) continue;

            int t = rec(s, i + 1, dp);
            if(t != INT_MAX)
            temp = min(temp, min(ones, zeros) + t);
        }
        return dp[idx] = temp;
    }

    int minChanges(string s) {
        // vector<int> dp(s.size(), -1);
        // return rec(s, 0, dp);

        int ans = 0;
        for(int i = 0; i < s.size(); i += 2) {
            if(s[i] != s[i + 1]) ans++;
        }
        return ans;
    }
};