class Solution {
public:
    int recursion(vector<int>& days, vector<int>& costs, int idx) {
        if(idx >= days.size()) return 0;

        int cost_1 = costs[0] + recursion(days, costs, idx + 1);

        int next_7_days = days[idx] + 7;
        int j = idx;
        while(j < days.size() && days[j] < next_7_days) {
            j++;
        }

        int cost_7 = costs[1] + recursion(days, costs, j);

        int next_30_day = days[idx] + 30;
        j = idx;
        while(j < days.size() && days[j] < next_30_day) {
            j++;
        }

        int cost_30 = costs[2] + recursion(days, costs, j);

        return min({cost_1, cost_7, cost_30});

    }

    int memoization(vector<int> &days, vector<int> &costs, vector<int> &dp, int idx) {

        if(idx >= days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        int cost_1 = costs[0] + memoization(days, costs, dp, idx + 1);

        int next_7_day = days[idx] + 7;
        int j = idx;
        while(j < days.size() && days[j] < next_7_day) {
            j++;
        }

        int cost_7 = costs[1] + memoization(days, costs, dp, j);

        int next_30_day = days[idx] + 30;
        j = idx;
        while(j < days.size() && days[j] < next_30_day) {
            j++;
        }

        int cost_30 = costs[2] + memoization(days, costs, dp, j);

        return dp[idx] = min({cost_1, cost_7, cost_30});

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        // Approach 1: recursion
        // return recursion(days, costs, 0);


        // Approach 2: memoization
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return memoization(days, costs, dp, 0);
    }
};