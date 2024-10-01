class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();

        int ans = INT_MIN;
        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            int start = -1, end = n;
            
            for(int i = 0; i < n; i++) {
                if(s[i] == ch && start == -1) {
                    start = i;
                }
                else if(s[i] == ch && start != -1) {
                    end = i;
                }
            }

            if(start != -1 && end != n) {
                ans = max(ans, end - start - 1);
            }
            else {
                ans = max(ans, -1);
            }
        }

        return ans;
    }
};