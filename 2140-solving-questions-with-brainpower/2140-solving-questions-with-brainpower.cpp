class Solution {
public:
    int recursion(vector<vector<int>>& questions, int idx) {
        if(idx >= questions.size()) return 0;
        
        int points = questions[idx][0];
        int brain_power = questions[idx][1];

        int take = points + recursion(questions, idx + brain_power + 1);
        // int take = 0;
        // if(idx + brain_power < questions.size()) {
        //     take = points + recursion(questions, idx + brain_power + 1);
        // }

        int skip = recursion(questions, idx + 1);

        return max(take, skip);
    }

    long long memoization(vector<vector<int>>& q, vector<long long> &dp, int idx) {
        if(idx >= q.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        long long take = q[idx][0] + memoization(q, dp, idx + q[idx][1] + 1);
        long long skip = memoization(q, dp, idx + 1);

        return dp[idx] = max(take, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // return recursion(questions, 0);

        // int n = questions.size();
        // vector<long long> dp(n + 1, -1);
        // return memoization(questions, dp, 0);

        int n = questions.size();
        vector<long long> dp(20001, 0);
        // dp[0] = questions[0][0];

        for(int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int brain_power = questions[i][1];
            dp[i] = max(points + dp[i + 1 + brain_power], dp[i + 1]);
        }

        return dp[0];
    }
};