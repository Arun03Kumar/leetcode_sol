class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), j = 0;
        string ans = "";
        for(int i = 0; i <= n; i++) {
            if(i == n || s[i] == ' ') {
                // string temp = s.substr(begin(s) + j, begin(s) + i);
                string temp = s.substr(j, i - j); // substr takes int not iterators
                reverse(begin(temp), end(temp));
                ans += temp + ' ';
                j = i + 1;
            }
        }
        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};