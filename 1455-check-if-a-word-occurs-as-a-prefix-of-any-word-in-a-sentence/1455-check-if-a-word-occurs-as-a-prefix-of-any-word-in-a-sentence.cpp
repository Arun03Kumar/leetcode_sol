class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int count = 1;
        while(ss >> word) {
            int i = 0;

            while(i < searchWord.size() && i < word.size()) {
                if(word[i] != searchWord[i]) break;
                i++;
            }

            if(i == searchWord.size()) return count;
            count++;
        }

        return -1;
    }
};