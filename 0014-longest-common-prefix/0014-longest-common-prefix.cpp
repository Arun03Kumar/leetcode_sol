class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string min_str = strs[0];
        for(string s: strs) {
            if(s.size() < min_str.size()) min_str = s;
        }

        string ans = min_str;
        for(string s: strs) {
            for(int i = 0; i < min_str.size(); i++) {
                if(min_str[i] == s[i]) continue;
                else {
                    ans = min_str.substr(0, i);
                    min_str = ans;
                    break;
                }
            }
        }
        return ans;
    }
};