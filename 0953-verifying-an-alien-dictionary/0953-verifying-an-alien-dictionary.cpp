class Solution {
public:
    // first create a map which contains the index of the characters in the alphabet
    // find the lenght of smaller word in the two adjecent words;
    // iterate over the length if corresponding character is smaller in first word it means that both words are in sorted order in this case we will continue search for other words.
    // if corresponding character in second word is larger than first word then it means they are not sorted, return false;
    // if we are at the index j = n - 1, where n is the length of smaller word then we will check if first word is smaller or second word. id second word is smaller then it means they are not sorted.(hello, he) here second word is smaller hence not sorted.
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ump;
        for(int i = 0; i < order.size(); i++) {
            ump[order[i]] = i;
        }

        for(int i = 0; i < words.size() - 1; i++) {
            string word = words[i];
            string next_word = words[i + 1];

            int min_length = min(word.size(), next_word.size());

            for(int j = 0; j < min_length; j++) {
                if(ump[word[j]] < ump[next_word[j]]) break;

                if(ump[word[j]] > ump[next_word[j]]) return false;

                if(j == min_length - 1 && word.size() > next_word.size()) {
                    return false;
                }
            }
        }

        return true;
    }
};