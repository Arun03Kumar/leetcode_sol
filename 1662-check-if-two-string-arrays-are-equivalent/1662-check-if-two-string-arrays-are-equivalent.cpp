class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string one = "", two = "";
        for(string x: word1) {
            one += x;
        }

        for(string x: word2) {
            two += x;
        }

        return one == two;
    }
};