class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);
        if(idx == string::npos) return word;

        reverse(begin(word), begin(word) + idx + 1);
        return word;
    }
};