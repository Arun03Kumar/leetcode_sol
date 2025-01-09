class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, n = words.size();

        for(string s: words) {
            if(s.find(pref) == 0) ans++;
        }

        return ans;
    }
};