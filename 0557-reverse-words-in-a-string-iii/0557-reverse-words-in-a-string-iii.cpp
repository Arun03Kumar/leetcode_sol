class Solution {
public:
    string reverseWords(string s) {
        int k = 0, tmp;
        string ans = "";
        while(k <= s.size()) {
            if(s[k] == ' ' || k == s.size()) {
                tmp = k - 1;
                while(tmp >= 0 && s[tmp] != ' ') {
                    ans += s[tmp];
                    tmp--;
                }
                if(k != s.size())
                    ans += " ";
            }
            k++;
        }
        return ans;
    }
};