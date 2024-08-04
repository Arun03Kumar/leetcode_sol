class Solution {
public:
    int M = 1e9 + 7;
    int recursion(vector<vector<int>> &moves, int n, int start) {
        if(n == 0) return 1;
        
        int temp = 0;
        for(int i = 0; i < moves[start].size(); i++) {
            temp += recursion(moves, n - 1, moves[start][i]);
        }

        return temp;
    }

    int memoization(vector<vector<int>> &moves, vector<vector<int>> &dp, int n, int start) {
        if(n == 0) return 1;

        if(dp[n][start] != -1) return dp[n][start];

        int temp = 0;
        for(int i = 0; i < moves[start].size(); i++) {
            temp = (temp % M + memoization(moves, dp, n - 1, moves[start][i]) % M) % M;
        }

        return dp[n][start] = (temp % M);
    }

    int knightDialer(int n) {
        vector<vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};

        // int ans = 0;
        // for(int i = 0; i <= 9; i++) {
        //     ans += recursion(moves, n - 1, i);
        // }

        // return ans;

        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        int ans = 0;
        for(int i = 0; i <= 9; i++) {
            ans = (ans % M + memoization(moves, dp, n - 1, i) % M) % M;
        } 

        return ans;
    }
};