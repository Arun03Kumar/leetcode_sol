class Solution {
public:
    bool recursion(string &s, int &min_jump, int &max_jump, int idx) {
        if(idx == s.size() - 1) return true;

        for(int i = idx + min_jump; i <= min(idx + max_jump, (int)s.size() - 1); i++) {

            if(s[i] == '0' && recursion(s, min_jump, max_jump, i)) {
                return true;
            }

        }

        return false;
    }

    bool memoization(string &s, int &min_jump, int &max_jump, int idx, vector<int> &dp) {
        if(idx == s.size() - 1) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int i = idx + min_jump; i <= min(idx + max_jump, (int)s.size() - 1); i++) {
            if(s[i] == '0' && memoization(s, min_jump, max_jump, i, dp)) {
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

     bool canReach(string s, int minJump, int maxJump) {
        // Approach 1: Recursion
        // return recursion(s, minJump, maxJump, 0);


        // Approach 2: Memoization
        // int n = s.size();
        // vector<int> dp(n, -1);
        // return memoization(s, minJump, maxJump, 0, dp);

        // Approach 3: Bottom up
        // int n = s.size();
        // if(s[n - 1] == '1') return false;
        // vector<bool> dp(n, false);
        // dp[0] = true;

        // for(int i = 1; i < n; i++) {
        //     if(s[i] == '0') {
        //         for(int j = i - 1; j >= 0; j--) {
        //             if(s[j] == '0' && dp[j] == 1 && (i >= j + minJump && i <= j + maxJump)) {
        //                 dp[i] = true;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return dp[n - 1];



        // Approach 4: Optimal
        queue<int> q;
        q.push(0);

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '0') {
                while(!q.empty() && q.front() < i - maxJump) q.pop();

                if(q.empty()) return false;
                int top = q.front();
                if(top + maxJump >= i && top + minJump <= i) {
                    q.push(i);
                    if(i == s.size() - 1) return true;
                }
            }
        }

        return false;

    }
};