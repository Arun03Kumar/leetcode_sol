class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string x = words[i];
                string y = words[j];

                if(y >= x && y.substr(0, x.size()) == x && y.substr(y.size() - x.size()) == x) {
                    ans++;
                }
            }
        }

        return ans;
    }
};