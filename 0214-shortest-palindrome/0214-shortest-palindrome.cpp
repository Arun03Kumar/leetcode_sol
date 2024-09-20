class Solution {
public:
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0; // Length of the previous longest prefix & suffix
    
        lps[0] = 0; // Because there is no proper suffix and prefix of pattern[0..0]
    
        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; //You can also write, len = len-1;
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        // Approach 1: O(n^2) and TC - O(n)
        // we need to find what is the longest palindrome present in the given string from start
        // if we know that then we just have to append the remaining string at the starting
        // to do this we can create a reverse string and then compare each suffix  of reverse with each prefix of given string.
        // ex - let s = abad then reverse will be rev = daba
        // now compare last 4 from rev to first 4 from s
        // then compare last 3 from rev to first 3 from s
        // and so on
        // we see that first 3 and last 3 is the longest palindrome present in the given string 
        // so we just have to append the remaining string which is 'd'

        // this will give memory limit exceeded because substr() function internally created temperory string which causes extra space.
        
        // string rev_string = s;
        // reverse(rev_string.begin(), rev_string.end());

        // int n = s.size();

        // for(int i = 0; i < n; i++) {

        //     if(s.substr(0, n - i) == rev_string.substr(i)) {
        //         return rev_string.substr(0, i) + s;
        //     }

        // }

        // return rev_string + s;


         string rev = s;
        reverse(begin(rev), end(rev));

        string temp = s + "-" + rev;

        vector<int> LPS(temp.length(), 0); //O(n)
        computeLPS(temp, LPS);

        int longestLPSLength = LPS[temp.length()-1]; //temp.back();

        string culprit = rev.substr(0, s.length() - longestLPSLength); //O(n)

        return culprit + s;
    }
};