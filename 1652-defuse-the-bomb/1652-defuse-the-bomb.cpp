class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // Approach 1: bruteforce
        int n = code.size();
        vector<int> ans(n, 0);

        if(k == 0) return ans;

        if(k > 0) {
            for(int i = 0; i < n; i++) {

                for(int j = 1; j <= k; j++) {
                    ans[i] += (code[(i + j) % n]);
                }

            }
        }
        else {
            for(int i = 0; i < n; i++) {

                for(int j = 1; j <= abs(k); j++) {
                    ans[i] += (code[(i - j + n) % n]);
                }

            }
        }

        return ans;
    }
};