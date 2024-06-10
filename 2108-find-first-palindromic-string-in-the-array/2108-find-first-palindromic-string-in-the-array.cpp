class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l <= r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string x: words) {
            if(isPalindrome(x))
                return x;
        }
        return "";
    }
};