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

        // we need to check by buying all 3 tickets at each day.
        // for one day pass its easy, but for 7 day and 30 day we need to check that if current date falls between 7 or 30 days if we buy those tickets.


        // Approach 1: recursion
        // return recursion(days, costs, 0);


        // Approach 2: memoization
        // int n = days.size();
        // vector<int> dp(n + 1, -1);
        // return memoization(days, costs, dp, 0);


        // Approach 3: bottom up

        // dp[i] this state tells that min amount needed to travel till this date
        // we can reach at date i if we bought ticket from last day, or i - 7 day or i - 30 day
        // we need set to find out if we are travelling on day i or not

        unordered_set<int> st;
        for(int day: days) st.insert(day);

        int n = days.size();
        int last_day = days[n - 1];

        vector<int> dp(last_day + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= last_day; i++) {
            if(st.find(i) == st.end()) {
                dp[i] = dp[i - 1];
                continue;
            }

            int cost_1 = costs[0] + dp[i - 1];
            int cost_7 = 0, cost_30 = 0;
            // if(i - 7 >= 0) {
            //     cost_7 = costs[1] + dp[i - 7];
            // }
            // else {
            //     cost_7 = costs[1] + dp[0];
            // }

            // we can do this if and else in shortcut as
            cost_7 = costs[1] + dp[max(0, i - 7)];

            if(i - 30 >= 0) {
                cost_30 = costs[2] + dp[i - 30];
            }
            else {
                cost_30 = costs[2] + dp[0];
            }

            dp[i] = min({cost_1, cost_7, cost_30});
        }

        return dp[last_day];
    }
};