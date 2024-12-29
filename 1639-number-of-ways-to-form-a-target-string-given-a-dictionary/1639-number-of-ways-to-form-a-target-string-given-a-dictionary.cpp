class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    int m;

    int recursion(string &target, int i, int j, vector<unordered_map<char, int>> &mp) {
        if(i >= target.size()) return 1;
        if(j >= m) return 0;

        int skip = recursion(target, i, j + 1, mp);
        int take = 0;
        if(mp[j].find(target[i]) != mp[j].end()) {
            take = (mp[j][target[i]] * 1LL * recursion(target, i + 1, j + 1, mp)) % mod;
        }

        return (skip % mod + take % mod) % mod;
    }

    int memoization(string &target, int i, int j, vector<unordered_map<char, int>> &mp, vector<vector<int>> &dp) {
        if(i >= target.size()) return 1;
        if(j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int skip = memoization(target, i, j + 1, mp, dp);
        int take = 0;
        if(mp[j].find(target[i]) != mp[j].end()) {
            take = (mp[j][target[i]] * 1LL * memoization(target, i + 1, j + 1, mp, dp)) % mod;
        }

        return dp[i][j] = (skip % mod + take % mod) % mod;
    }

    int numWays(vector<string>& words, string target) {
        n = words.size();
        m = words[0].size();
        vector<unordered_map<char, int>> mp(m);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[i][words[j][i]]++;
            }
        }

        // return recursion(target, 0, 0, mp);

        int k = target.size();
        vector<vector<int>> dp(k + 1, vector<int>(m + 1, -1));
        return memoization(target, 0, 0, mp, dp);

    }
};