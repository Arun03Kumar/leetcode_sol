class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for(char ch: s) freq[ch - 'a']++;

        string ans = "";

        int i = 25;
        while(i >= 0) {
            if(freq[i]) {
                int rep = min(repeatLimit, freq[i]);
                ans.append(rep, 'a' + i);

                freq[i] -= rep;
                
                if(freq[i] > 0) {
                    int j = i - 1;
                    while(j >= 0 && !freq[j]) j--;

                    if(j < 0) break;

                    ans.push_back('a' + j);
                    freq[j]--;
                }
            }
            else
                i--;
        }

        return ans;
    }
};