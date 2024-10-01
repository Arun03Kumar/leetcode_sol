class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0;
        for(char &ch: s) {
            if(ch == '0') zeros++;
            else ones++;
        }

        int temp_0 = 0, temp_1 = 0;
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++) {

            if(s[i] == '0') temp_0++;
            else temp_1++;

            ans = max(ans, temp_0 + ones - temp_1);
        }

        return ans;
    }
};