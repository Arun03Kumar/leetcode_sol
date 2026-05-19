class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i = s.size() - 1; i >= 0; i--) {
            if(i < s.size() - 1 && m[s[i + 1]] > m[s[i]]) {
                ans -= m[s[i]];
            }
            else ans += m[s[i]];
        }
        return ans;
    }
};