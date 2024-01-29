class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.size() - 1;
        while(st <= e) {
            if(!isalnum(s[st])) {
                st++;
                continue;
            }
            if(!isalnum(s[e])) {
                e--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[e])) {
                return false;
            }
            st++;
            e--;
        }
        return true;
        // string updated_s = "";
        // for(int i = 0; i < s.size(); i++) {
        //     if((isalpha(s[i])) || (isdigit(s[i]))) {
        //         if(isupper(s[i]))
        //             updated_s += tolower(s[i]);
        //         else
        //             updated_s += s[i];
        //     }
        // }
        // string rev = "";
        // for(int i = updated_s.size() - 1; i >= 0; i--) {
        //     rev += updated_s[i];
        // }

        // return rev == updated_s ? true : false;
    }
};