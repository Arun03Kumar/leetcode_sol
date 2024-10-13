class Solution {
public:
    int memoization(int n, vector<int> &dp) {
        if(n <= 1) return 1;

        if(dp[n] != -1) return dp[n];

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int left = memoization(i - 1, dp);
            int right = memoization(n - i, dp);

            ans += left * right;
        }

        return dp[n] = ans;
    }
    int numTrees(int n) {
       // we can create BSTs starting from each number
        // if we are at ith number then in left subtree there will be subtrees created by i-1 nodes and in right there will be subtrees creates by all n-i nodes
        // so if we can find the number of BSTs in the left and number of BSts in the right then we can simply multiply them to get the BSTs for node i as the root

        // if(n <= 1) return 1;

        // int ans = 0;
        // for(int i = 1; i <= n; i++) {
        //     int left = numTrees(i - 1);
        //     int right = numTrees(n - i);

        //     ans += left * right;
        // } 

        // Approach 2: Memoization
        // vector<int> dp(n + 1, -1);
        // return memoization(n, dp);

        // Approach 3: Top down
        // vector<int> dp(n + 1, 0);
        // dp[0] = dp[1] = 1;

        // for(int i = 2; i <= n; i++) {
        //     for(int j = 1; j <= i; j++) {
        //         dp[i] += dp[j - 1] * dp[i - j];
        //     }
        // }

        // return dp[n];

        // Approach 4: Catalan number
        // 1 1 2 5 14 42 132 ...
        // formula:
        // C(n) = C(n - 1) * ((4*n - 2) / (n + 1))

        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            ans = (ans * (4 * i - 2)) / (i + 1);
        }
        return (int)ans;
    }
};