class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // string one = "", two = "";
        // for(string x: word1) {
        //     one += x;
        // }

        // for(string x: word2) {
        //     two += x;
        // }

        // return one == two;

        int word1ptr = 0, word2ptr = 0, charPtr1 = 0, charPtr2 = 0;
        while(word1ptr < word1.size() && word2ptr < word2.size()) {
            if(word1[word1ptr][charPtr1++] != word2[word2ptr][charPtr2++]) 
                return false;

            if(charPtr1 == word1[word1ptr].size()) {
                word1ptr++;
                charPtr1 = 0;
            }

            if(charPtr2 == word2[word2ptr].size()) {
                word2ptr++;
                charPtr2 = 0;
            }            
        }
        return word1ptr == word1.size() && word2ptr == word2.size();
    }
};