class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n - 1;
        string ans = "", temp = "";

        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0) {
            if(s[i] == ' ') {
                reverse(begin(temp), end(temp));
                ans += temp;
                temp = "";
                ans += ' ';
                while(i >= 0 && s[i] == ' ') i--;
                
            }
            else {
               temp.push_back(s[i]);
                i--; 
            }
        }

        if(!temp.empty()) {
            reverse(begin(temp), end(temp));
            ans += temp;
        }

        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};