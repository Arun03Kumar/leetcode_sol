class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        while(i < str1.size() && j < str2.size()) {
            char curr_char = str1[i];
            char next_char = (str1[i] == 'z' ? 'a' : str1[i] + 1);
            if(curr_char == str2[j] || next_char == str2[j]) {
                j++;
            }
            i++;
        }

        if(j == str2.size()) return true;

        return false;
    }
};