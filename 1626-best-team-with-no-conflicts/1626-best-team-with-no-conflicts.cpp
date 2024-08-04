class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<pair<int, int>> combined;
        for(int i = 0; i < n; i++) {
            combined.push_back({ages[i], scores[i]});
        }

        sort(begin(combined), end(combined));

        vector<int> dp(n + 1, 0);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
           dp[i] = combined[i].second;

           for(int j = 0; j < i; j++) {

                if(combined[j].second <= combined[i].second) {
                    dp[i] = max(dp[i], combined[i].second + dp[j]);
                }
           } 

           ans = max(ans, dp[i]);
        }

        return ans;
    }
};