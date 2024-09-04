class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;

        vector<string> words;

        string temp = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                // cout << temp << " ";
                words.push_back(temp);
                temp.clear();
            }
            else {
                temp += s[i];
            }  
        }
        words.push_back(temp);

        if(words.size() != pattern.size()) return false;

        // for(string &x: words) cout << x << " ";
        for(int i = 0; i < pattern.size(); i++) {

            char ch = pattern[i];
            string word = words[i];
            if((m1.find(ch) != m1.end() && m1[ch] != word) || (m2.find(word) != m2.end() && m2[word] != ch)) return false;

            m1[ch] = word;
            m2[word] = ch;

        }

        return true;
    }
};