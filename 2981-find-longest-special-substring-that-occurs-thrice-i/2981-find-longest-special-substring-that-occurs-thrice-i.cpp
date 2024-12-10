class Solution {
public:
    int maximumLength(string s) {
        //Approach 1: Brute force - find all substrings and create a map
        // int n = s.size();
        // unordered_map<string, int> mp;

        // for(int i = 0; i < n; i++) {
        //     string curr = "";
        //     for(int j = i; j < n; j++) {
        //         if(curr == "" || curr.back() == s[j]) {
        //             curr.push_back(s[j]);
        //             mp[curr]++;
        //         }
        //         else {
        //             break;
        //         }
        //     }
        // }

        // int ans = -1;
        // for(auto [key, val]: mp) {
        //     if(val >= 3) {
        //         ans = max(ans, (int)key.size());
        //     }
        // }

        // return ans;

        // Approach 2: we can improve the space 
        // we don't need the actual string, so we can create a map and store the {char, length} pair
        int n = s.size();
        map<pair<char, int>, int> mp; // mp[{char, length}] = frequency

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int length = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == ch) {
                    length++;
                    mp[{ch, length}]++;
                }
                else break;
            }
        }

        int ans = -1;
        for(auto [key, val]: mp) {
            if(val >= 3) {
                ans = max(ans, int(key.second));
            }
        }
        return ans;
    }
};