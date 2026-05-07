class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> f_map, b_map;

        for(int i = 0; i < s.size(); i++) {
            int ch1 = s[i];
            int ch2 = t[i];

            if(f_map.count(ch1)) {
                if(f_map[ch1] != ch2) return false;
            }
            else f_map[ch1] = ch2;

            if(b_map.count(ch2)) {
                if(b_map[ch2] != ch1) return false;
            }
            else b_map[ch2] = ch1;
        }
        return true;
    }
};