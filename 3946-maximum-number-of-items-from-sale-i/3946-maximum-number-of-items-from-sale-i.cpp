class Solution {
public:
    vector<int> copies;
    int compute(vector<vector<int>>& arr, int idx) {
        return copies[arr[idx][0]];
        int cnt = 0;
        int den = arr[idx][0];

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i][0] % den == 0) {
                cnt++;
            }
        }

        return cnt;
    }

    int rec(vector<vector<int>>& arr, int idx, int target,
            vector<vector<int>>& dp) {

        if(idx == arr.size()) return 0;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        int price = arr[idx][1];

        // Option 1: Skip current item
        int notTake = rec(arr, idx + 1, target, dp);

        // Option 2: Buy current item k times
        int take = 0;

        int freeItems = compute(arr, idx);

        for(int k = 1; k * price <= target; k++) {

            int remaining = target - k * price;

            int curr = freeItems + k;

            curr += rec(arr, idx + 1, remaining, dp);

            take = max(take, curr);
        }

        return dp[idx][target] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        // int n = items.size();
        // copies.resize(1501, -1);

        // for(int i = 0; i < n; i++) {
        //     int copy = 0;
        //     for(int j = 0; j < n; j++){
        //         if(j != i) {
        //             if(items[j][0] % items[i][0] == 0) copy++;
        //         }
        //     }
        //     copies[items[i][0]] = copy;
        // }

        // sort(items.begin(), items.end(),
        //      [](vector<int>& a, vector<int>& b) {
        //          return a[1] < b[1];
        //      });

        

        // vector<vector<int>> dp(
        //     n + 1, vector<int>(budget + 1, -1)
        // );

        // return rec(items, 0, budget, dp);
        int n = items.size();

        vector<int> copies(n, 0); //copies[i] = count of copies if I buy ith item
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            int copy = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        vector<vector<int>> t(n + 1, vector<int>(budget + 1, 0));

        // Base case: no item types left, spend leftover on the cheapest item
        //n = 0
        for (int b = 0; b <= budget; b++)
            t[0][b] = b / minPrice;

        for (int i = 1; i <= n; i++) {
            for (int b = 0; b <= budget; b++) {
                int price = items[i - 1][1];
                int take = 0;

                if (price <= b)
                    take = 1 + copies[i - 1] + t[i - 1][b - price];

                int skip = t[i - 1][b];

                t[i][b] = max(take, skip);
            }
        }

        return t[n][budget];
    }
};