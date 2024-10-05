class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;

        if(s.size() < 10) return {};

        string window = "";
        for(int i = 0; i < 10; i++) window += s[i];

        int l = 0, r = 10;
        for(int i = 0; i <= s.size() - 10; i++) {
            mp[window]++;
            cout << window << endl;
            window += s[r];
            window.erase(begin(window));
            // l++;
            r++;
        }

        vector<string> ans;
        for(auto [key, val]: mp) {
            if(val > 1) {
                ans.push_back(key);
            }
        }

        return ans;
    }
};