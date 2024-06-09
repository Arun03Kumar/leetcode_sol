class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, e = s.size() - 1;
        while(st <= e) {
            if(s[st] != s[e])
                return false;
            st++;
            e--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        if(isPalindrome(s)) return true;
        int st = 0, e = s.size() - 1;
        string left = s, right = s;
        while(st <= e) {
            if(s[st] != s[e]) {
                left.erase(left.begin() + st);
                right.erase(right.begin() + e);
                return isPalindrome(left) || isPalindrome(right);
            }
            st++;
            e--;
        }
        return false;
    }
};