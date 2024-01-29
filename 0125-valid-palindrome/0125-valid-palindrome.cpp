class Solution {
public:
    bool isPalindrome(string s) {
        string updated_s = "";
        for(int i = 0; i < s.size(); i++) {
            if((isalpha(s[i])) || (isdigit(s[i]))) {
                if(isupper(s[i]))
                    updated_s += tolower(s[i]);
                else
                    updated_s += s[i];
            }
        }
        string rev = "";
        for(int i = updated_s.size() - 1; i >= 0; i--) {
            rev += updated_s[i];
        }

        return rev == updated_s ? true : false;
    }
};