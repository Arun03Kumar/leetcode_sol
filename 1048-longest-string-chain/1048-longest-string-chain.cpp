class Solution {
public:
    bool is_pred(const string &a, const string &b) {
        int m = a.size(), n = b.size();
        if(m >= n || n - m != 1) return false;

        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                i++;
            }
            j++;
        }

        return i == m;
    }

    int recursion(vector<string>& words, int idx, int prev) {
        if(idx >= words.size()) return 0;

        int take = 0;
        if(prev == -1 || is_pred(words[prev], words[idx])) {
            take = 1 + recursion(words, idx + 1, idx);
        }

        int skip = recursion(words, idx + 1, prev);

        return max(take, skip);
    }

    int memoization(vector<string>& words, vector<vector<int>> &dp, int idx, int prev) {
        if(idx >= words.size()) return 0;

        if(prev != -1 && dp[prev][idx] != -1) return dp[prev][idx];

        int take = 0;
        if(prev == -1 || is_pred(words[prev], words[idx])) {
            take = 1 + memoization(words, dp, idx + 1, idx);
        }

        int skip = memoization(words, dp, idx + 1, prev);

        if(prev != -1) {
            dp[prev][idx] = max(take, skip);
        }

        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        // it is also variation of LIS.
        // we first sort the given words in increasing order of their lengths.
        // then we need to check if we are taking the current word then it should be predecessor of previous word, to check that we create a helper function in which we send the previous word and current word
        // previous word should have one less length than current and it should be subsequence of the current word.
        // to check the subsequence we can take pointers which points to the character of each word and if both points to same character then we can increase the pointers and we can check if smaller word pointer reached at end.

        auto comparator = [](const string &x, const string &y) {
            return x.size() < y.size();
        };
        sort(words.begin(), words.end(), comparator);



        // Appraoch 1: recursion
        // return recursion(words, 0, -1); 
        
        int n = words.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return memoization(words, dp, 0, -1);

        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++) {
        //     ans = max(ans, dp[i]);
        // }

        // return ans;
    }
};