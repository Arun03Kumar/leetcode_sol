class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> freq;
        for(char &ch: chars) freq[ch]++;
        int ans = 0;

        for(string &s: words) {

            unordered_map<char, int> copy_freq = freq;
            bool flag = false;
            for(int i = 0; i < s.size(); i++) {
                if(copy_freq.find(s[i]) == copy_freq.end() || copy_freq[s[i]] <= 0) {
                    flag = true;
                    break;
                }
                copy_freq[s[i]]--;
            }

            if(!flag) ans += s.size();

        }

        return ans;
    }
};