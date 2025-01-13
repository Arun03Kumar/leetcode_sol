class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for(char ch: s) {
            freq[ch - 'a']++;
        }

        int ans = 0;
        for(int &x: freq) {
            if(x > 2) {
                if(x % 2 == 0) ans += 2;
                else ans += 1;
            }
            else ans += x;
        }

        return ans;
    }
};