class Solution {
public:
    int maximumLength(string s) {
        // Brute force - find all substrings and create a map
        int n = s.size();
        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++) {
            string curr = "";
            for(int j = i; j < n; j++) {
                if(curr == "" || curr.back() == s[j]) {
                    curr.push_back(s[j]);
                    mp[curr]++;
                }
                else {
                    break;
                }
            }
        }

        int ans = -1;
        for(auto [key, val]: mp) {
            if(val >= 3) {
                ans = max(ans, (int)key.size());
            }
        }

        return ans;
    }
};