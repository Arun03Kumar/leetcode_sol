class Solution {
public:
    int search_map(unordered_map<char, int> ump) {
        int max_ = INT_MIN;
        for(auto x: ump) { 
            max_ = max(max_, x.second);
        }
        return max_;
    }

    int characterReplacement(string s, int k) {
       unordered_map<char, int> ump;
       int l = 0, r = 0, res = 0;
        while(r < s.size()) {
            ump[s[r]]++;
            while(r - l + 1 - search_map(ump) > k) { 
                ump[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};