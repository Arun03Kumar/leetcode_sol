class Solution {
public:
    int lengthOfLastWord(string s) {
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == ' ') continue;
            if(s[i] != ' ') {
                int j = i, count = 0;
                while(j >= 0 && s[j] != ' ') {
                    j--;
                    count++;
                }
                return count;
            }
        }
        return -1;
    }
};