class Solution {
public:
    string removeChars(string s) {
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '#' && i != 0) {
                s.erase(s.begin() + i - 1, s.begin() + i + 1);
                i -= 1;
            }
            else if(i == 0 && s[i] == '#') {
                s.erase(0, 1);
            }
            else 
                i++;
        }
        return s;
    }
    bool backspaceCompare(string s, string t) {
        string ans1 = removeChars(s);
        string ans2 = removeChars(t);
        // cout << ans1 << " d " << ans2;
        return ans1 == ans2 ? true : false;
    }
};