class Solution {
public:
    bool check(string &s, int i, int j) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // we use two pointer approach we start from both ends and if characters are same we move to next characters
        // but if a character is not matched we can check if remaining characters will form palindrome or not because before those string will be palindrome because then only we have came to that point

        int i = 0, j = s.size() - 1;
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                bool x = check(s, i + 1, j); // exclude i, and check remaining 
                bool y = check(s, i, j - 1);// exlcude j and check remaining
                
                // since we can remove only at most time hence we are returning directly here, even if it not palindrome after excluding
                return x || y;
            }

        }

        return true;
    }
};