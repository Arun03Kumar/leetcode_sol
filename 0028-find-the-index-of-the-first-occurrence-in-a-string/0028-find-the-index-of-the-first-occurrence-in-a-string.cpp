class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, n = haystack.length(), m = needle.length();
        while(i < n) {
            if(haystack[i] != needle[0]) {
                i++;
                continue;
            }
            bool flag = true;
            int back = 0;
            for(int j = 0; j < m; j++) {
                if(needle[j] != haystack[i+j]) {
                    i += j;
                    flag = false;
                    break;
                } else if(j != 0 && needle[j] == haystack[i+j] && haystack[i+j] == needle[0]) {
                    back = j;
                }
            }
            if(flag) break;
            i -= back;
        }
        if(i != n) return i;
        else return -1; 
    }
};