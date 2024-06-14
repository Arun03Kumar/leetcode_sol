class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0, res = 0, total = 0, r = k;
        for(int i = 0; i < k; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                res++;
                total++;
            }
        }
        // total = res;
        while(r < s.size()) {
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                total--;
            }
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                total++;
            }
            res = max(res, total);
            r++;
            l++;
        }
        return res;
    }
};