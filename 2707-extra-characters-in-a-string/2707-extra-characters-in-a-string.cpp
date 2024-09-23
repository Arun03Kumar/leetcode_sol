class Solution {
public:
    int recursion(string s, unordered_set<string>& dict, int idx){
        if(idx >= s.size()) return 0;

        int skip = 1 + recursion(s, dict, idx + 1);
        int take = INT_MAX;

        for(int i = idx; i < s.size(); i++) {
            string temp = s.substr(idx, i - idx + 1);
            if(dict.find(temp) != dict.end()) {
                take = min(take, recursion(s, dict, i + 1));
            }
        }

        return min(take, skip);

    }

    int memoization(string s, unordered_set<string>& dict, int idx, vector<int> &dp) {
        if(idx >= s.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int skip = 1 + memoization(s, dict, idx + 1, dp);
        int take = INT_MAX;

        for(int i = idx; i < s.size(); i++) {
            string temp = s.substr(idx, i - idx + 1);
            if(dict.find(temp) != dict.end()) {
                take = min(take, memoization(s, dict, i + 1, dp));
            }
        }

        return dp[idx] = min(take, skip);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        // return recursion(s, st, 0);

        vector<int> dp(s.size() + 1, -1);
        return memoization(s, st, 0, dp);
    }
};