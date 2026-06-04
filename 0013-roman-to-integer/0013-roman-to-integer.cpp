class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> d = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(i != n - 1 && d[s[i]] < d[s[i + 1]]) {
                ans -= d[s[i]];
            }
            else ans += d[s[i]];
        }
        return ans;
    }
};