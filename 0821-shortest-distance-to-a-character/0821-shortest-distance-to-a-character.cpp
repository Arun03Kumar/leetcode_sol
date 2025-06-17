class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                ans[i] = 0;
                continue;
            }
            int j = i + 1;
            for(; j < n; j++) {
                if(s[j] == c) break;
            }

            int k = i - 1;
            for(; k >= 0; k--) {
                if(s[k] == c) break;
            }

            if(k < 0) ans[i] = abs(j - i);
            else if(j >= n) ans[i] = abs(i - k);
            else ans[i] = min(abs(j - i), abs(i - k));
        }

        return ans;
    }
};