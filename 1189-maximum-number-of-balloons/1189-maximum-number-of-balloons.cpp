class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        mp['b'] = mp['a'] = mp['l'] = mp['o'] = mp['n'] = 0;
        
        for(char &ch: text) {
            if(mp.find(ch) != mp.end()) mp[ch]++;
        }

        int ans = INT_MAX;
        for(auto &x: mp) {
            char ch = x.first;
            int freq = x.second;
            cout << ch << " ";

            if(ch == 'l' || ch == 'o') {
                ans = min(ans, mp[ch] / 2);
            }
            else {
                ans = min(ans, mp[ch]);
            }
        }

        return ans;
    }
};