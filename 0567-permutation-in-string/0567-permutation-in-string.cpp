class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> s1_hash(26, 0), s2_hash(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            s1_hash[s1[i] - 'a']++;
            s2_hash[s2[i] - 'a']++;
        }

        int l = 0, r = s1.size();
        while(r < s2.size()) { 
            if(s1_hash == s2_hash) return true;
            s2_hash[s2[r] - 'a']++;
            s2_hash[s2[l] - 'a']--;
            l++;
            r++;
        }
        return s1_hash == s2_hash;
    }
};