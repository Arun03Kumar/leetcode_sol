class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};
        for(char c: s) {
            int val = c - 'a';
            freq[val]++;
        }

        int x = freq[s[0] - 'a'];
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] != x) return false;
        }

        return true;
    }
};