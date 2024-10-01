class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // since we have to make all words equal so we can calculate frequency of each letters in all words and we can find if we can equally divide each letters in the size of array

        int n = words.size();
        vector<int> freq(26, 0);

        for(string &s: words) {
            for(char &ch: s) {
                char c = ch - 'a';
                freq[c]++;
            }
        }

        for(int &x: freq) {
            if(x % n != 0) return false;
        }

        return true;
    }
};