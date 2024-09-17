class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;

        string temp = "";
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] == ' ') {
                freq[temp]++;
                temp = "";
            }
            else {
                temp += s1[i];
            }
        }
        freq[temp]++;

        temp = "";
        for(int i = 0; i < s2.size(); i++) {
            if(s2[i] == ' ') {
                freq[temp]++;
                temp = "";
            }
            else {
                temp += s2[i];
            }
        }
        freq[temp]++;

        vector<string> ans;
        for(auto &[key, val]: freq) {
            if(val == 1) ans.push_back(key);
        }

        return ans;
    }
};