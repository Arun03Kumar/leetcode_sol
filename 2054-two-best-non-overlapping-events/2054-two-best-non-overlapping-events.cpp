class Solution {
public:
    int binary_search(vector<vector<int>> &events, int end) {
        int l = 0, r = events.size() - 1;

        int ans = r + 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(events[mid][0] > end) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
    int recursion(vector<vector<int>> &events, int idx, int count) {
        if(count == 2 || idx >= events.size()) return 0;

        int next_valid_idx = binary_search(events, events[idx][1]);
        int take = events[idx][2] + recursion(events, next_valid_idx, count + 1);

        int skip = recursion(events, idx + 1, count);

        return max(take, skip);

    }

    int memoization(vector<vector<int>> &events, int idx, int count, vector<vector<int>> &dp) {
        if(count == 2 || idx >= events.size()) return 0;

        if(dp[idx][count] != -1) return dp[idx][count];

        int next_valid_idx = binary_search(events, events[idx][1]);
        int take = events[idx][2] + memoization(events, next_valid_idx, count + 1, dp);
        int skip = memoization(events, idx + 1, count, dp);

        return dp[idx][count] = max(take, skip);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));

        // return recursion(events, 0, 0);
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return memoization(events, 0, 0, dp);
    }
};