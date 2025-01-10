class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // we don't need the sum of each character instead we need the max frequency of chanracters in any of the words
        
        vector<int> w2(26, 0);
        for (string s : words2) {
            vector<int> temp(26, 0);
            for (char ch : s) {
                temp[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                w2[i] = max(w2[i], temp[i]);
            }
        }

        vector<string> ans;
        for (string s : words1) {
            vector<int> w1(26, 0);
            for (char ch : s) {
                w1[ch - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (w1[i] < w2[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                ans.push_back(s);
            }
        }

        return ans;

    }
};