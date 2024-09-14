class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // we could also use DP solution but it can be done in nlogn using greedy
        // we can use the difference as our choosing factor to
        // how much cost we can save if we choose to go to city A rather B, so we will find the difference and which difference will be maximum we can choose them to send to city A, then rest half to city B
        int n = costs.size();

        auto comp = [&](auto x, auto y) {
            return (x[1] - x[0]) > (y[1] - y[0]);
        };
        sort(begin(costs), end(costs), comp);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += i >= n / 2 ? costs[i][1] : costs[i][0];
        }

        return ans;
    }
};